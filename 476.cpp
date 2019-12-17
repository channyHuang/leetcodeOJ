class Solution {
public:
    int findComplement(int num) {
        int pos = 0;
        int res = 0;
        while (num) {
            if (num & 1) pos++;
            else {
                res += (1 << pos);
                pos++;
            }
            num >>= 1;
        }
        return res;
    }
};
