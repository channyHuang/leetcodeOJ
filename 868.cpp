class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int count = -1;
        while (N) {
            if (N & 1) {
                if (count == -1) count = 0;
                else {
                    count++;
                    if (count > res) res = count;
                    count = 0;
                }
            } else {
                if (count != -1) count++;
            }
            N >>= 1;
        }
        return res;
    }
};
