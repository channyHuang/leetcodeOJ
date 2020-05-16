class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> nodes[N + 1];
        int len = dislikes.size();
        int used[N + 1];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < len; i++) {
            nodes[dislikes[i][0]].push_back(dislikes[i][1]);
            nodes[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> qu;
        while (1) {
            int i;
            for (i = 1; i <= N; i++) {
                if (used[i] == 0) {               
                    qu.push(i);
                    used[i] = 1;
                    break;
                }
            }
            if (i > N) return true;
            while (!qu.empty()) {
                int cur = qu.front();
                qu.pop();
                for (i = 0; i < nodes[cur].size(); i++) {
                    if (used[nodes[cur][i]] == 0) {
                        used[nodes[cur][i]] = -used[cur];
                        qu.push(nodes[cur][i]);
                    }
                    else if (used[nodes[cur][i]] != -used[cur]) return false;
                }
            }
        }
        return true;
    }
};
