class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if (len == 2) return area(height, 0, 1);
        int maxn[len] = {0};
        maxn[1] = area(height, 0, 1);
        int res = maxn[1];
        for (int i = 2; i < len; i++) {
            maxn[i] = maxn[i - 1];
            for (int j = i - 1; j >= 0; j--) {
                int tmp = area(height, j, i);
                if (maxn[i] < tmp) maxn[i] = tmp;
            }

            if (res < maxn[i]) res = maxn[i];
        }
        return res;
    }

    int area(vector<int>& height, int stPos, int endPos) {
        if (stPos >= endPos) return 0;
        return (height[stPos] < height[endPos] ? height[stPos] : height[endPos]) * (endPos - stPos);
    }
};
