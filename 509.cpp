class Solution {
public:
    int fib(int N) {
        int f[32] = {0, 1, 1, 2, 3,
        5, 8, 13, 21, 34,
        55, 89, 144, 233, 377, 
        610, 987, 1597, 2584, 4181};
        if (N < 20) return f[N];
        
        for (int i = 20; i <= N; i++) {
            f[i] = f[i - 2] + f[i - 1];
        }
        return f[N];
    }
};
