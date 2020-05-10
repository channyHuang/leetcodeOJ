class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int len = arr.size();
        if (len == 1) return arr[0];
        int pre[len], rev[len];
        memset(pre, 0, sizeof(pre));
        memset(rev, 0, sizeof(rev));
        int res = arr[0];
        pre[0] = arr[0];
        for (int i = 1; i < len; i++) {
            if (arr[i] < pre[i - 1] + arr[i]) pre[i] = pre[i - 1] + arr[i];
            else pre[i] = arr[i];
            res = max(pre[i], res);
        }
        rev[len - 1] = arr[len - 1];
        res = max(rev[len - 1], res);
        for (int j = len - 2; j >= 0; j--) {
            if (arr[j] < rev[j + 1] + arr[j]) rev[j] = rev[j + 1] + arr[j];
            else rev[j] = arr[j];
            res = max(rev[j], res);
        }
        for (int i = 1; i < len - 1; i++) {
            res = max(res, pre[i - 1] + rev[i + 1]);
        }
        return res;
    }
};
