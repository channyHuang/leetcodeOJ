class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        if (len <= 0) return 0;
        if (len == 1) return 1;
        int res = 0;
        int pos = 0;
        int maxn = arr[0];
        while (pos < len) {
            maxn = arr[pos];
            for (; pos <= maxn; pos++) {
                if (arr[pos] > maxn) maxn = arr[pos];
            }
            res++;
        }
        return res;
    }
};
