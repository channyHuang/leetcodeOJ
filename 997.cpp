class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int count[1005] = {0};
        if (N == 0) return -1;
        if (N == 1) return 1;
        vector<int> res;
        for (int i = 0; i < trust.size(); i++) {
            count[trust[i][0]] = -1;
            if (count[trust[i][1]] == -1) continue;
            count[trust[i][1]]++;           
            if (count[trust[i][1]] == N - 1) res.push_back(trust[i][1]);
        }
        for (int i = 0; i < res.size(); i++) 
            if (count[res[i]] != -1) return res[i];
        return -1;
    }
};
