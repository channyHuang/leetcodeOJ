class Solution {
public:
    class Node {
    public:
        int idx;
        int count;
        vector<int> neig;
    };

    static bool cmp(const Node& a, const Node& b) {
        if (a.count == b.count) return a.idx < b.idx;
        return a.count < b.count;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 0) return res;
        if (n <= 2) {
            for (int i = 0; i < n; i++) 
                res.push_back(i);
            return res;
        }
        int len = edges.size();
        vector<Node> nodes;
        nodes.resize(n);
        for (int i = 0; i < len; i++) {
            nodes[i].idx = i;
            nodes[edges[i][0]].neig.push_back(edges[i][1]);
            nodes[edges[i][1]].neig.push_back(edges[i][0]);
            nodes[edges[i][0]].count++;
            nodes[edges[i][1]].count++;
        }
        
        queue<int> qu[2];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nodes[i].count == 1) qu[0].push(i);
        }
        while (1) {
            if (qu[idx].empty()) break;
            res.clear();
            while (!qu[idx].empty()) {
                int usedIdx = qu[idx].front();
                res.push_back(usedIdx);
                qu[idx].pop();
                nodes[usedIdx].count = 0;
                for (int i = 0; i < nodes[usedIdx].neig.size(); i++) {
                    if (nodes[nodes[usedIdx].neig[i]].count > 1) {
                        nodes[nodes[usedIdx].neig[i]].count--;
                        if (nodes[nodes[usedIdx].neig[i]].count == 1) qu[1 - idx].push(nodes[usedIdx].neig[i]);
                    }
                }
            }
            idx = 1 - idx;
        }

        return res;
    }
};
