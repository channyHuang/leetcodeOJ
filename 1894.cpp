class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int len = chalk.size();
        long long sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += chalk[i];
            if (sum > k) return i;
        }
        k %= sum;
        sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += chalk[i];
            if (sum > k) return i;
        }
        return 0;
    }
};
