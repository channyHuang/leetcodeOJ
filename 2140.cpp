class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int len = questions.size();
        vector<long long> maxn(len, 0);
        vector<long long> curpick(len, 0);
        curpick[len - 1] = questions[len - 1][0];
        maxn[len - 1] = curpick[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            curpick[i] = questions[i][0];
            int nextidx = i + questions[i][1] + 1;
            if (nextidx < len) {
                curpick[i] += maxn[nextidx]; 
            }
            maxn[i] = std::max(curpick[i], maxn[i + 1]);
        }
        return maxn[0];
    }
};
