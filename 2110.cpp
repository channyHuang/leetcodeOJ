class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long len = prices.size();
        if (len <= 1) return len;
        long long stpos = 0, endpos = 1;
        long long res = 0;
        while (stpos < len) {
            while (endpos < len && prices[endpos] == prices[endpos - 1] - 1) endpos++;
            long long curlen = (endpos - stpos);
            long long tmp = (1 + curlen) * curlen;
            tmp >>= 1;
            res += tmp;
            stpos = endpos;
            endpos = stpos + 1;
        }
        return res;
    }
};
