class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> path;
        path.resize(10005);
        for (int i = 0; i < paths.size(); i++) {
            path[paths[i][0]].push_back(paths[i][1]);
            path[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> res;
        res.resize(N);
        res[0] = 1;
        for (int i = 1; i < N; i++) {
            int used[5] = {0};
            for (int j = 0; j < path[i + 1].size(); j++) {       
                used[res[path[i + 1][j] - 1]] = 1;
            }
            for (int j = 1; j <= 4; j++) {
                if (used[j] == 0) {
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
    }
};
