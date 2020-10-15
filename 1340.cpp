class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        len = arr.size();
        res = 0;
        dp.resize(len);
        for (int i = 0; i < len; i++) {
            dp[i] = 0;
        }
        dir = d;
        for (int i = 0; i < len; i++) {
            if (dp[i] <= 0) {
                search(arr, i);
            }
            res = max(res, dp[i]);
        }/*
        for (int i = 0; i < len; i++) {
            cout << dp[i] <<  ;
        }
        cout << endl;
        cout << res << endl;*/
        return res;
    }


    void search(vector<int>& arr, int index) {
        dp[index] = 1;
        bool bLeft = true, bRight = true;
        for (int i = 1; i <= dir; i++) {
            if (bRight) {
                if (index + i >= len) bRight = false;
                else {
                    if (arr[index + i] >= arr[index]) {
                        bRight = false;
                    } else {
                        if (dp[index + i] <= 0) search(arr, index + i);
                        dp[index] = max(dp[index], 1 + dp[index + i]);
                    }
                }
            }
            if (bLeft) {
                if (index - i < 0) bLeft = false;
                else {
                    if (arr[index - i] >= arr[index]) {
                        bLeft = false;
                    } else {
                        if (dp[index - i] <= 0) search(arr, index - i);
                        dp[index] = max(dp[index], 1 + dp[index - i]);
                    }
                }
            }
            if (!bRight && !bLeft) break;
        }
    }


private:
    vector<int> dp;
    int dir;
    int len;
    int res;
};
