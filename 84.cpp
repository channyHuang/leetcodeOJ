class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len <= 0) return 0;
        if (len == 1) return heights[0];
        int res = heights[0];
        for (int i = 0; i < len; i++) {
            if (i > 0 && heights[i] == heights[i - 1]) continue;
            int count = 0;
            int j;
            for (j = i + 1; j < len; j++) {
                if (heights[i] > heights[j]) break;
            }
            count += (j - i);
            for (j = i - 1; j >= 0; j--) {
                if (heights[i] > heights[j]) break;
            }
            count += (i - j - 1);
            
            res = max(res, count * heights[i]);
        }
        return res;
    }
};
