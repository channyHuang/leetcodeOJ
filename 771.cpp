class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool count[256] = {0};
        int res = 0;
        int lenj = J.length(), lens = S.length();
        for (int i = 0; i < lenj; i++) {
            count[J[i]] = true;
        }
        for (int i = 0; i < lens; i++) {
            if (count[S[i]]) res++;
        }
        return res;
    }
};
