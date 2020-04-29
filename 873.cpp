class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int len = A.size();
        int res = 0;
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (dp[i][j] > 2) continue;
                dp[i][j] = 2;
                int pos = i; 
                int nextPos = j;
                while (1) {
                    int idx = find(A, A[pos] + A[nextPos], j + 1, len - 1);
                    if (idx == -1) break;
                    if (dp[nextPos][idx] < dp[pos][nextPos] + 1) {
                        dp[nextPos][idx] = dp[pos][nextPos] + 1;
                        res = max(dp[nextPos][idx], res);
                        pos = nextPos;
                        nextPos = idx;
                    } else break;
                }
            }
        }
        return (res >= 3 ? res : 0);
    }

    int find(vector<int>& A, int target, int stPos, int endPos) {
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (A[midPos] == target) return midPos;
            else if (A[midPos] < target) stPos = midPos + 1;
            else endPos = midPos - 1;
        }
        return -1;
    }
};
