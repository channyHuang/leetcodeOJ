class Solution {
public:
    int minAddToMakeValid(string S) {
        int len = S.length();
        if (len <= 0) return 0;
        int count = 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (S[i] == '(') count++;
            else {
                if (count) count--;
                else {
                    res++;
                }
            }
        }
        res += count;
        return res;
    }
};
