class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += machines[i];
        }
        if (sum % len != 0) return -1;
        int eachMachine = sum / len;
        int res = 0;
        sum = 0;
        for (int i = 0; i < len; i++) {
            machines[i] -= eachMachine;
            res = max(res, machines[i]);
            sum += machines[i];
            res = max(res, abs(sum));
        }
        return res;
    }
};
