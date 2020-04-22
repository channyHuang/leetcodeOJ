class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long res = (long long)(D - B) * (C - A) + (G - E) * (H - F);
        if (A >= G || E >= C) return res;
        if (B >= H || F >= D) return res;
        int xmin = max(A, E);
        int xmax = min(C, G);
        int ymin = max(B, F);
        int ymax = min(H, D);
        return res - (ymax - ymin) * (xmax - xmin);
    }
};
