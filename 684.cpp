class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int parent[1005] = {0};
        int len = edges.size();
        if (len <= 0) return res;
        parent[edges[0][0]] = edges[0][0];
        parent[edges[0][1]] = edges[0][0];
        for (int i = 1; i < edges.size(); i++) {
            int pa = findParent(parent, edges[i][0]);
            int pb = findParent(parent, edges[i][1]);

            if (pa == 0 && pb == 0) {
                parent[edges[i][0]] = edges[i][0];
                parent[edges[i][1]] = edges[i][0];
            } else if (pa == 0) {
                parent[edges[i][0]] = pb;
            } else if (pb == 0) {
                parent[edges[i][1]] = pa;
            } else if (pa == pb) {
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
                return res;
            } else {
                parent[pb] = pa;
            }
        }
        return res;
    }

    int findParent(int parent[1005], int pos) {
        if (parent[pos] == 0) return 0;
        if (parent[pos] == pos) return pos;
        int res = parent[pos];
        while (parent[res] != 0 && parent[res] != res) res = parent[res];
        return res;
    }
};
