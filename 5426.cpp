class Solution {
public:
    class Node {
    public:
        int val;
        vector<int> neighbor;
        vector<bool> dir;
    };

    int minReorder(int n, vector<vector<int>>& connections) {
        Node nodes[n];
        vector<bool> used(n, false);
        for (int i = 0; i < connections.size(); i++) {
            nodes[connections[i][0]].neighbor.push_back(connections[i][1]);
            nodes[connections[i][0]].dir.push_back(true);
            nodes[connections[i][1]].neighbor.push_back(connections[i][0]);
            nodes[connections[i][1]].dir.push_back(false);
        }
        queue<int> qu;
        qu.push(0);
        int res = 0;
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            used[cur] = true;
            for (int i = 0; i < nodes[cur].neighbor.size(); i++) {
                if (used[nodes[cur].neighbor[i]]) continue;
                qu.push(nodes[cur].neighbor[i]);
                if (nodes[cur].dir[i]) res++;
            }
        }
        return res;
    }
};
