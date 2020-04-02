class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        int label[len];
        for (int i = 0; i < len; i++) {
            label[i] = -1;
        }
        queue<int> qu;
        int count = 1;
        for (int i = 0; i < len; i++) {
            if (label[i] != -1) continue;
            qu.push(i);
            label[i] = 0;
            while (!qu.empty()) {
                int idx = qu.front();
                qu.pop();
                for (int j = 0; j < graph[idx].size(); j++) {
                    if (label[graph[idx][j]] == -1) {
                        label[graph[idx][j]] = 1 - label[idx];
                        count++;
                        qu.push(graph[idx][j]);
                    } else if (label[graph[idx][j]] != 1 - label[idx]) return false;
                }
            }
        }
        return true;
    }
};
