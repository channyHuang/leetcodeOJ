class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
        int len2 = arr2.size();
        sort(arr2.begin(), arr2.end());
        int pos = 0;
        for (int i = 1; i < len2; i++) {
            if (arr2[i] == arr2[pos]) continue;
            pos++;
            arr2[pos] = arr2[i];
        }
        len2 = pos + 1;
        vector<vector<int>> dp(len1, vector<int>(len2 + 1, INT_MAX));
        dp[0][0] = 0;
        for (int j = 0; j < len2; j++) {
            if (arr1[0] <= arr2[j]) break;
            dp[0][j + 1] = 1;
        }
        int res = INT_MAX;
        for (int i = 1; i < len1; i++) {
            if (arr1[i] > arr1[i - 1]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
            for (int j = 0; j < len2; j++) {
                if (arr1[i] > arr2[j]) {
                    dp[i][0] = min(dp[i][0], dp[i - 1][j + 1]);
                }
                if (arr2[j] > arr1[i - 1] && dp[i - 1][0] <= len1) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][0] + 1);
                }
                if (j > 0 && dp[i - 1][j] <= len1) {
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + 1);
                }
            }
            /*
            for (int x = 0; x <= len2; x++) {
                cout << dp[i][x] << " ";
            }
            cout << endl;*/
        }

        for (int j = 0; j <= len2; j++) {
            res = min(res, dp[len1 - 1][j]);
        }

        return (res == INT_MAX ? -1 : res);
    }
};
