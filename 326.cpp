class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        //不能循环或者递归，就只有充分利用条件：int的范围，3是质数
        return 1162261467 % n ? false : true;
    }
};
