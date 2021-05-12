class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int people[105] = {0};
        int len = logs.size();
        for (int i = 0; i < len; i++) {
            people[logs[i][0] - 1950]++;
            people[logs[i][1] - 1950]--;
        }
        int maxn = 0;
        int res = 0;
        int sum = 0;
        for (int i = 0; i < 105; i++) {
            sum += people[i];
            if (sum > maxn) {
                maxn = sum;
                res = i;
            }
        }
        return res + 1950;
    }
};
