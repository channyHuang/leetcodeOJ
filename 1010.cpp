class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[505] = {0};
        for (int i = 0; i < time.size(); i++) {
            count[time[i]]++;
        }
        int res = 0;
        for (int i = 0; i < time.size(); i++) {
            count[time[i]]--;
            for (int j = 60; j < 1000; j += 60) {
                int target = j - time[i];
                if (target <= 0 || target > 500) continue;
                res += count[target];
            }
        }
        return res;
    }
};
