class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len = grumpy.size();
        if (X >= len) {
            int sum = 0;
            for (int i = 0; i < len; i++) {
                sum += customers[i];
            }
            return sum;
        }
        int sum[len] = {0};
        sum[0] = (grumpy[0] ? 0 : customers[0]);
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i - 1] + (grumpy[i] ? 0 : customers[i]);
        }
        int maxn = 0;
        int endPos = X - 1;
        for (int j = X - 1; j >= 0; j--) {
            if (grumpy[j]) maxn += customers[j];
        }
        int lastMaxn = maxn;
        for (int i = X; i < len; i++) {
            int tmpmaxn = lastMaxn;
            if (grumpy[i - X]) tmpmaxn -= customers[i - X];
            if (grumpy[i]) tmpmaxn += customers[i];
            if (tmpmaxn > maxn) {
                maxn = tmpmaxn;
                endPos = i;
            }
            lastMaxn = tmpmaxn;
        }
        return maxn + sum[len - 1];
    }
};
