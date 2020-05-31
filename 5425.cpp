class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int lenh = horizontalCuts.size();
        int lenv = verticalCuts.size();
        int maxh = max(horizontalCuts[0], h - horizontalCuts[lenh - 1]);
        for (int i = 1; i < lenh; i++) {
            if (horizontalCuts[i] - horizontalCuts[i - 1] > maxh) maxh = horizontalCuts[i] - horizontalCuts[i - 1];
        }
        int maxv = max(verticalCuts[0], w - verticalCuts[lenv - 1]);
        for (int i = 1; i < lenv; i++) {
            if (verticalCuts[i] - verticalCuts[i - 1] > maxv) maxv = verticalCuts[i] - verticalCuts[i - 1];
        }
        long long res = maxh;
        res *= maxv;
        return (res % 1000000007);
    }
};
