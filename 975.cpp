class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        len = A.size();
        if (len <= 1) return len;
        vector<vector<int>> dp(len, vector<int>(2, -1));
        map<int, queue<int>> maps;
        map<int, queue<int>>::iterator itr;
        map<int, queue<int>>::iterator nitr;
        for (int i = 0; i < len; i++) {
            maps[A[i]].push(i);
        }
        for (int i = 0; i < len; i++) {
            itr = maps.find(A[i]);
            if (itr->second.size() == 1) {
                nitr = itr;
                nitr++;
                if (nitr != maps.end()) {
                    dp[i][0] = nitr->second.front();
                }
                nitr = itr;
                if (nitr != maps.begin()) {
                    nitr--;
                    dp[i][1] = nitr->second.front();
                }
                maps.erase(itr);
            } else {
                itr->second.pop();
                dp[i][0] = itr->second.front();
                dp[i][1] = itr->second.front();
            }
        }
        /*for (int i = 0; i < len; i++) {
            cout << dp[i][0] << " " << dp[i][1] << endl;
        }*/
        int res = 1;
        for (int i = 0; i < len - 1; i++) {
            int curIdx = i;
            bool bOddJump = true;
            while (curIdx != len - 1) {
                if (bOddJump && dp[curIdx][0] != -1) {
                    curIdx = dp[curIdx][0];
                } else if (!bOddJump && dp[curIdx][1] != -1) {
                    curIdx = dp[curIdx][1];
                } else {
                    break;
                }
                bOddJump = !bOddJump;
            }
            if (curIdx == len - 1) res++;
        }
        return res;
    }
private:
    int len;
};
