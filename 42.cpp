class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len <= 2) return 0;
        int stPos = 0;
        int endPos = len - 1;
        while (stPos < endPos && height[stPos + 1] > height[stPos]) stPos++;
        while (stPos < endPos && height[endPos - 1] > height[endPos]) endPos--;
        return calc(height, stPos, endPos);
    }

    int calc(vector<int>& height, int stPos, int endPos) {
        if (stPos >= endPos) return 0;
        if (stPos == endPos - 1) return 0;
        int maxH = height[stPos + 1];
        int idx = stPos + 1;
        int res = 0;
        for (int i = stPos + 1; i < endPos; i++) {
            if (maxH < height[i]) {
                maxH = height[i];
                idx = i;
            }
        }
        if (maxH >= height[stPos] || maxH >= height[endPos]) {
            return calc(height, stPos, idx) + calc(height, idx, endPos);
        } else {
            int maxH = min(height[stPos], height[endPos]);
            for (int i = stPos + 1; i < endPos; i++) {
                res += (maxH - height[i]);
            }
        }
        return res;
    }
};
