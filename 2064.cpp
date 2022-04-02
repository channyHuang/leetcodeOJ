class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int len = quantities.size();
        sort(quantities.begin(), quantities.end());
        if (n == len) return quantities[len - 1];
        // len < n
        int minn = 1, maxn = quantities[len - 1];
        int res = maxn;
        while (minn <= maxn) {
            int midn = ((minn + maxn) >> 1);
            int targetn = 0;
            for (int i = len - 1; i >= 0; --i) {
                if (quantities[i] <= midn) {
                    targetn += i + 1;
                    break;
                }
                targetn += (quantities[i] / midn + (quantities[i] % midn == 0 ? 0 : 1));
                if (targetn > n) break;
            }
            
            if (targetn > n) {
                minn = midn + 1;
            } else {
                res = std::min(res, midn);
                maxn = midn - 1;
            }
        }
        return res;
    }
};

