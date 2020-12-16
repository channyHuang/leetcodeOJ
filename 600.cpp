class Solution {
public:
    int findIntegers(int num) {
        dp.resize(32, 0);
        dp[1] = 2;
        dp[2] = 3;
        for (int i = 3; i <= 31; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dfs(num);
    }

    int dfs(int num) {
        if (num <= 2) return num + 1;
        if (num == 3) return num;

        int bit = 3;
        while (num >= (1 << bit)) bit++;

        if ((num >> (bit - 2)) == 3) {//start with 11
            return dp[bit];
        } 
        return dp[bit - 1] + dfs(num & ((1 << bit) + (1 << (bit - 2)) - 1));
    }
private:
    vector<int> dp; //dp[i] bit is i all result
};
