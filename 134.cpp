class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if (len <= 0) return 0;
        int totalGas = 0;
        int totalCost = 0;
        for (int i = 0; i < len; i++) {
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if (totalGas < totalCost) return -1;
        if (len <= 1) return 0;
        for (int i = 0; i < len; i++) {
            if (gas[i] < cost[i]) continue;
            int leftGas = gas[i] - cost[i];
            int j;
            for (j = 1; j < len; j++) {
                int idx = (i + j) % len;
                leftGas += gas[idx] - cost[idx];
                if (leftGas < 0) break;
            }
            if (j == len) return i;
        }
        return -1;
    }
};