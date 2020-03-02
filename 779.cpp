class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        if (N == 2) return 1 - (K & 1);
        int x = kthGrammar(N - 1, (K + 1) / 2);
        if (x == 0) {
            if (K & 1) return 0;
            else return 1;
        } else {
            if (K & 1) return 1;
            else return 0;
        }
        return 0;
    }
};
