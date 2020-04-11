class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int, int>> nodes[n];
        for (int i = 0; i < edges.size(); i++) {
            nodes[edges[i][0]].push_back(pair<int, int>(edges[i][1], edges[i][2]));
            nodes[edges[i][1]].push_back(pair<int, int>(edges[i][0], edges[i][2]));
        }
        int finIdx = n - 1;
        int finCnt = n;
        for (int i = n - 1; i >= 0; i--) {
            queue<pair<int, int>> qu;
            qu.push(pair<int, int>(i, 0));
            int used[n];
            for (int j = 0; j < n; j++) used[j] = -1;
            used[i] = 0;
            int res = 0;
            while (!qu.empty()) {
                pair<int, int> cur = qu.front();
                qu.pop();
                for (int j = 0; j < nodes[cur.first].size(); j++) {
                    if (cur.second + nodes[cur.first][j].second > distanceThreshold) continue;
                    if (used[nodes[cur.first][j].first] == -1) res++;
                    if (used[nodes[cur.first][j].first] == -1 || used[nodes[cur.first][j].first] > cur.second + nodes[cur.first][j].second) {
                        used[nodes[cur.first][j].first] = cur.second + nodes[cur.first][j].second;
                        qu.push(pair<int, int>(nodes[cur.first][j].first, nodes[cur.first][j].second + cur.second));
                    }
                }
            }
            if (res < finCnt) {
                finIdx = i;
                finCnt = res;
            }
        }
        return finIdx;
    }
};
