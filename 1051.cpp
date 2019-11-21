class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int len = heights.size();
        if (len <= 1) return 0;
        int res = 0;
        int count[105] = {0};
        for (int i = 0; i < len; i++) count[heights[i]]++;

        int curPos = 0;
        for (int i = 0; i < 101; i++) {
            if (count[i] == 0) continue;
            for (int j = 0; j < count[i]; j++) {
                if (heights[curPos++] != i) res++;
            }
        }
        return res;
    }
};
