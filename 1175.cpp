class Solution {
public:
    int numPrimeArrangements(int n) {
        if (n <= 2) return 1;
        else if (n == 3) return 2;
        int prim[30] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        int mod = 1000000007;
        int count = 0;
        for (; count < 30; count++) {
            if (prim[count] <= n && prim[count + 1] > n) break;
        }
        count++;
        long long res = 1;
        
        //count!(n - count)!
        for (int i = 2; i <= n - count; i++) {
            res = res * i % mod;
        }
        if (count == 0) return res;
        for (int i = 2; i <= count; i++) {
            res = res * i % mod;
        }
        return res;
    }
};
