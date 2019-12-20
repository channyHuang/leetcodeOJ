class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len = points.size();
        map<int, int> count;
        map<int, int>::iterator itr; 
        int res = 0;
        int dis[len][len] = {0};
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                dis[i][j] = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                dis[j][i] = dis[i][j];
            }

            count.clear();
            for (int j = 0; j < len; j++) {
                if (j == i) continue;
                itr = count.find(dis[i][j]);
                if (itr == count.end()) count.insert(make_pair(dis[i][j], 1));
                else {
                    res += itr->second;
                    itr->second++;                  
                }
            }
        }
        return (res << 1);
    }
};
