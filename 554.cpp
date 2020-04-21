class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int len = wall.size();
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                itr = maps.find(sum);
                if (itr == maps.end()) {
                    maps.insert(pair<int, int>(sum, 1));
                } else itr->second++;
            }
        }
        int res = -1;
        int count = 0;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (res == -1) {
                res = itr->first;
                count = itr->second;
            }
            if (itr->second > count) {
                res = itr->first;
                count = itr->second;
            }
        }
        return len - count;
    }
};
