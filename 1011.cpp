class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int len = weights.size();
        if (len <= 0) return 0;
        int sum = weights[0];
        int maxn = weights[0];
        for (int i = 1; i < len; i++) {
            sum += weights[i];
            if (maxn < weights[i]) maxn = weights[i];
        }
        if (D == 1) return sum;
        int stPos = maxn, endPos = sum;
        while (stPos < endPos) {
            int midPos = (stPos + endPos) / 2;
            int dayw = 0;
            int day = 0;
            for (int i = 0; i < len; i++) {
                if (dayw + weights[i] > midPos) {
                    day++;
                    dayw = weights[i];
                } else dayw += weights[i];
            }
            if (dayw != 0) {
                dayw = 0;
                day++;
            }
            if (day > D) stPos = midPos + 1;
            else endPos = midPos;
        }
        return stPos;
    }
};
