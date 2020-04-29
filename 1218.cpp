class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len = arr.size();
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int res = 1;
        map<int, vector<int>> maps;
        map<int, vector<int>>::iterator itr;
        {
            vector<int> sub;
            sub.push_back(0);
            maps.insert(pair<int, vector<int>>(arr[0], sub));
        }
        for (int i = 1; i < len; i++) {
            dp[i] = 1;
            int lastArr = arr[i] - difference;
            itr = maps.find(lastArr);
            if (itr != maps.end()) {
                int lastLen = itr->second.size();
                dp[i] = max(dp[i], dp[itr->second[lastLen - 1]] + 1);
            }

            itr = maps.find(arr[i]);
            if (itr != maps.end()) {
                itr->second.push_back(i);
            } else {
                vector<int> sub;
                sub.push_back(i);
                maps.insert(pair<int, vector<int>>(arr[i], sub));
            }
            res = max(dp[i], res);
        }
        return res;
    }
};
