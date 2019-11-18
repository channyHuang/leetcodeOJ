class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        else if (n == 2) return 2;
        else if (n == 3) return 3;
        //else return climbStairs(n-1) + climbStairs(n-2);*/

        int res[n + 1] = {0};
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        res[3] = 3;
        for (int i = 4; i <= n; i++) res[i] = res[i - 1] + res[i - 2];
        return res[n];
    }
};
