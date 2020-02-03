class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        int x = n - 1;
        int y = 1;
        int tmp = 0;
        while (1) {
            tmp = minusval(x);
            if (tmp == 0) {
                if (minusval(y) == 0) {
                    res.push_back(x);
                    res.push_back(y);
                    break;
                } else {
                    y++;
                    x--;
                }
            } else {
                x -= tmp;
                y += tmp;
            }
        }
        return res;
    }
    
    int minusval(int n) {
        int x = n;
        int bit = 1;
        while (x) {
            if (x % 10 == 0) return bit;
            bit *= 10;
            x /= 10;
        }
        return 0;
    }
};