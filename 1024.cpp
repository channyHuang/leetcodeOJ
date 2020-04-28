class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int len = clips.size();
        sort(clips.begin(), clips.end(), cmp);
        if (clips[0][0] != 0) return -1;
        vector<vector<int>> newclips;
        newclips.push_back(clips[0]);
        int count = 1;
        for (int i = 1; i < len; i++) {
            if (clips[i][0] == newclips[count - 1][0]) continue;
            if (clips[i][1] <= newclips[count - 1][1]) continue;
            newclips.push_back(clips[i]);
            count++;
        }
        int dp[101];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        len = count;
        count = 0;
        for (int i = 1; i <= T; i++) {
            if (i <= newclips[count][1]) dp[i] = dp[i - 1];
            else {
                count++;
                if (count >= len) break;
                if (i <= newclips[count][0]) return -1;
                dp[i] = dp[newclips[count][0]] + 1;
            }
        }
        if (dp[T] == 0) return -1;
        return dp[T];
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
};
