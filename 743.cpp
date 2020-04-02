class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int mytimes[N + 1];
        vector<vector<pair<int, int>>> edges;
        edges.resize(N + 1);
        for (int i = 0; i < times.size(); i++) {
            edges[times[i][0]].push_back(pair<int, int>(times[i][1], times[i][2]));
        }
        for (int i = 1; i <= N; i++) mytimes[i] = -1;
        queue<int> qu;
        qu.push(K);
        int res = 0;
        mytimes[K] = 0;
        while (!qu.empty()) {
            int idx = qu.front();
            qu.pop();
            for (int j = 0; j < edges[idx].size(); j++ ) {
                pair<int, int> curPair = edges[idx][j];
                if (curPair.first == K) continue;
                if (mytimes[curPair.first] == -1) {
                    mytimes[curPair.first] = mytimes[idx] + curPair.second;
                    qu.push(curPair.first);
                } else if (mytimes[curPair.first] > mytimes[idx] + curPair.second) {
                    mytimes[curPair.first] = mytimes[idx] + curPair.second;
                    qu.push(curPair.first);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if (mytimes[i] == -1) return -1;
            if (mytimes[i] > res) {
                res = mytimes[i];
            }
        }
        return res;
    }
};
