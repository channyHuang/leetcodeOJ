class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        int len = points.size();
        int maxn = 2;
        vector<int> repeat(len, 0);
        vector<int> res = {0, 1};
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int count = 2;
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    // same point
                    repeat[i]++;
                    continue;
                } else if (points[i][0] == points[j][0]) {
                    // same x
                    for (int k = j + 1; k < len; ++k) {
                        if (points[k][0] == points[i][0]) count++;
                    }
                } else if (points[i][1] == points[j][1]) {
                    // same y
                    for (int k = j + 1; k < len; ++k) {
                        if (points[k][1] == points[i][1]) count++;
                    }
                } else {
                    long long diffy = points[i][1] - points[j][1];
                    long long diffx = points[i][0] - points[j][0];

                    for (int k = j + 1; k < len; ++k) {
                        long long diffxx = points[i][0] - points[k][0];
                        long long diffyy = points[i][1] - points[k][1];

                        if (diffxx * diffy == diffyy * diffx) count++;
                    }
                }
                count += repeat[i];
                if (count > maxn) {
                    maxn = count;
                    res[0] = i;
                    res[1] = j;
                }
            }
        }
        return res;
    }
};

