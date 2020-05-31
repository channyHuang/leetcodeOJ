class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = pow(2, k);
        if (s.length() <= k) return false;
        vector<bool> has(len, false);
        int num = 0;
        for (int i = 0; i < k; i++) {
            num = (num << 1) + s[i] - '0';
        }
        int res = 0;
        has[num] = true;
        res++;
        for (int i = k; i < s.length(); i++) {
            num = num - ((s[i - k] - '0') << (k - 1));
            num = (num << 1) + s[i] - '0';
            if (has[num]) continue;
            has[num] = true;
            res++;
        }
        return (res == len);
    }
};
