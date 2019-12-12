class Solution {
public:
    int subtractProductAndSum(int n) {
        long long mul = 1;
        long long add = 0;
        while (n) {
            int m = n % 10;
            mul *= m;
            add += m;
            n /= 10;
        }
        return mul - add;
    }
};
