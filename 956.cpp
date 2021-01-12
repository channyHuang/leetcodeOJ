class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        len = rods.size();
        if (len <= 1) return 0;
        if (len == 2) return (rods[0] == rods[1] ? rods[0] : 0);
        sort(rods.begin(), rods.end(), greater());
        sum.resize(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            sum[i] = sum[i - 1] + rods[i - 1];
        }
        maxSum = (sum[len] >> 1);
        dfs(rods, 0, 0, 0);
        return maxn;
    }

    void dfs(vector<int>& rods, int pos, int positive, int negative) {
        if (positive == negative && positive > maxn) {
            maxn = positive;
        }
        if (pos >= len) {
            return;
        }
        
        if (positive > maxSum || negative > maxSum) return;
        if (abs(positive - negative) > sum[len] - sum[pos]) return;
        if (max(positive, negative) + ((sum[len] - sum[pos]) >> 1) < maxn) return;

        dfs(rods, pos + 1, positive + rods[pos], negative);
        dfs(rods, pos + 1, positive, negative + rods[pos]);
        dfs(rods, pos + 1, positive, negative);
    }

private:
    int len;
    int maxn = 0;
    vector<int> sum;
    int maxSum;
};
