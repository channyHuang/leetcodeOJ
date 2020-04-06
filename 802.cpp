class Solution {
public:
    class Node {
    public:
        int idx;
        int out;
        vector<int> from;
    };

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> res;
        vector<Node> nodes;
        nodes.resize(len);
        for (int i = 0; i < len; i++) {
            nodes[i].idx = i;
            for (int j = 0; j < graph[i].size(); j++) {
                nodes[graph[i][j]].from.push_back(i);
            }
            nodes[i].out = graph[i].size();
        }
        queue<int> qu[2];
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (nodes[i].out == 0) {
                qu[0].push(i);
            }
        }
        while (1) {
            if (qu[pos].empty()) break;
            while (!qu[pos].empty()) {
                int idx = qu[pos].front();
                res.push_back(idx);
                qu[pos].pop();
                for (int i = 0; i < nodes[idx].from.size(); i++) {
                    nodes[nodes[idx].from[i]].out--;
                    if (nodes[nodes[idx].from[i]].out == 0) qu[1 - pos].push(nodes[idx].from[i]);
                }
            }
            pos = 1 - pos;
        }
        if (res.size() > 0) sort(res.begin(), res.end());
        return res;
    }
};
