class Solution {
public:
    int clumsy(int N) {
        if (N == 1) return 1; 
        if (N == 2) return 2; //2*1
        if (N == 3) return 6; //3*2/1
        if (N == 4) return 7; //4*3/2+1
        if (N == 5) return 7; //5*4/3+2-1
        if (N == 6) return 8; //6*5/4+3-2*1
        return N * (N - 1) / (N - 2) + subclumsy(N - 3);
    }

    int subclumsy(int N) {
        if (N == 1) return 1; // 1
        if (N == 2) return 1; // 2 - 1
        if (N == 3) return 1; //3 - 2 * 1
        if (N == 4) return -2; // 4 - 3 * 2 / 1
        if (N == 5) return 0; // 5 - 4 * 3 / 2 + 1
        return N - (N - 1) * (N - 2) / (N - 3) + subclumsy(N - 4);
    }
};
