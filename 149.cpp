class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if (len <= 1) return len;
        int res = 1;

        for (int i = 0; i < len; i++) {
            map<pair<int, int>, int> maps;
            int same = 1;
            int vertical = 0;
            int horizontal = 0;
            for (int j = i + 1; j < len; j++) {
                if ((points[j][0] == points[i][0]) && (points[j][1] == points[i][1])) {
                    same++;
                } else if (points[j][0] == points[i][0]) {
                    vertical++;
                } else if (points[j][1] == points[i][1]) {
                    horizontal++;
                } else {
                    //x != 0 and y != 0
                    int y = points[j][1] - points[i][1];
                    int x = points[j][0] - points[i][0];
                    bool positive = true;
                    if (y < 0) {
                        positive = !positive;
                        y = -y;
                    }
                    if (x < 0) {
                        positive = !positive;
                        x = -x;
                    }

                    int factor = maxFactor(x, y);

                    int nx = x / factor;
                    int ny = y / factor;
                    if (!positive) {
                        nx = -nx;
                    }

                    maps[pair<int, int>(nx, ny)]++;
                }
            }

            int maxn = max(vertical, horizontal);
            for (map<pair<int, int>, int>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
                if (itr->second > maxn) maxn = itr->second;
            }
            res = max(res, same + maxn);
        }

        return res;
    }

    int maxFactor(int x, int y) {
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        if (x == 0) return y;
        return maxFactor(x, y % x);
    }
};
