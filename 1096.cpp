// 关键在于nums[i]只有[1,100],考虑从遍历nums[i]的值入手
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int nlen = nums.size();
        vector<vector<int>> sum(nlen + 1, vector<int>(105, 0));
        for (int i = 0; i < nlen; ++i) {
            for (int j = 1; j <= 100; ++j) { // nums[i] [1, 100]
                sum[i + 1][j] = sum[i][j];
            }
            sum[i + 1][nums[i]]++;
        }
        int qlen = queries.size();
        vector<int> res(qlen, -1);
        for (int i = 0; i < qlen; ++i) {
            int pre = 0;
            for (int j = 1; j <= 100; ++j) {
                if (sum[queries[i][1] + 1][j] - sum[queries[i][0]][j] == 0) continue;
                if (pre == 0) pre = j;
                else if (res[i] == -1) {
                    res[i] = j - pre;
                    pre = j;
                } else {
                    res[i] = std::min(res[i], j - pre);
                    pre = j;
                }
            }
        }
        return res;
    }
};
