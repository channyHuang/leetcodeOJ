class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int len = arr.size();
        if (len == 1) {
            if (arr[0] > 0) return arr[0] * k;
            return 0;
        }
        long long res = 0;
        long long pre[len];
        memset(pre, 0, sizeof(pre));
        long long maxpre = 0, maxrev = 0;
        long long sum = 0;
        for (int i = 0; i < len; i++) {
            if (i == 0) pre[i] = arr[0];
            else {
                if (arr[i] < pre[i - 1] + arr[i]) pre[i] = pre[i - 1] + arr[i];
                else pre[i] = arr[i];
            }
            res = max(res, pre[i]);
            sum += arr[i];        
            maxpre = max(maxpre, sum);
        }
        sum = 0;
        for (int j = len - 1; j >= 0; j--) {
            sum += arr[j];
            maxrev = max(maxrev, sum);
        }
        if (sum >= 0) {
            res = max(res, ((long long)sum * (k - 2) % maxn + maxpre + maxrev) % maxn);
        } else {
            res = max(res, (maxrev + maxpre) % maxn);
        }
        return res;
    }

private:
    int maxn = 1000000007;
};
