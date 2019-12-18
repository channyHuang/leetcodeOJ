class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool odd = n & 1;
        n >>= 1;
        while(n) {
            if ((n & 1) != odd) {
                odd = !odd;
                n >>= 1;
            } else return false;
        }
        return true;
    }
};
