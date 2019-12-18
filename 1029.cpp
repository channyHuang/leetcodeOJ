class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int len = costs.size();
        if (len <= 0) return 0;
        int index[len] = {0};
        int diff[len] = {0};
        diff[0] = costs[0][0] - costs[0][1];
        for (int i = 1; i < len; i++) {
            diff[i] = costs[i][0] - costs[i][1];
            int count = 0;
            for (int j = 0; j < i; j++) {
                if (diff[j] > diff[i]) {
                    index[j]++;
                    count++;
                }
            }
            index[i] = i - count;
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (index[i] < len / 2) {
                res += costs[i][0];
            } else res += costs[i][1];
        }
        return res;
    }
};
