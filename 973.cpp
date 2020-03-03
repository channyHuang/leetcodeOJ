class Solution {
public:
    class Node {
    public:
        double dist;
        int idx;
        Node (int _idx = 0, double _dist = 0) {
            dist = _dist;
            idx = _idx;
        }
    };

    static int cmp(const void *a, const void *b) {
        return (*((Node *)a)).dist > (*((Node *)b)).dist;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int len = points.size();
        if (len == K) return points;
        Node nodes[len];
        for (int i = 0; i < len; i++) {
            nodes[i] = Node(i, distance(points, i));
        }
        qsort(nodes, len, sizeof(Node), cmp);
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            vector<int> subres;
            subres.push_back(points[nodes[i].idx][0]);
            subres.push_back(points[nodes[i].idx][1]);
            res.push_back(subres);
        }
        return res;
    }

    double distance(vector<vector<int>>& points, int idx) {
        return (double)(points[idx][0] * points[idx][0] + points[idx][1] * points[idx][1]);
    }
};
