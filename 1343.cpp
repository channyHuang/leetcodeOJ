class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int len = arr.size();
        if (len <= 0) return 0;
        if (len == 1) {
            return (k == 1 && arr[0] >= threshold ? 1 : 0);
        }
        int sum[len];
        memset(sum, 0, sizeof(sum));
        sum[0] = arr[0];
        int res = 0;
        int totalSum = k * threshold;
        for (int i = 1; i < k; i++) {
            sum[i] = sum[i - 1] + arr[i];
        }
        if (sum[k - 1] >= totalSum) res++;
        for (int i = k; i < len; i++) {
            sum[i] = sum[i - 1] - arr[i - k] + arr[i];
            if (sum[i] >= totalSum) res++;
        }
        return res;
    }
};
