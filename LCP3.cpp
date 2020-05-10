class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int dx = 0, dy = 0;
        map<int, set<int>> maps;
        map<int, set<int>>::iterator itr;
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'U') dy++;
            else dx++;
        }
        if (abs(x / dx - y / dy) > 1) return false;
        int len = obstacles.size();
        for (int i = 0; i < len; i++) {
            int ox = obstacles[i][0];
            int oy = obstacles[i][1];
            //if (ox == x && oy == y) return false;
            if (ox > x || oy > y) continue;
            
            int cnt = min(ox / dx, oy / dy);
            ox -= cnt * dx;
            oy -= cnt * dy;
            if (ox > dx || oy > dy) continue;
            itr = maps.find(ox);
            if (itr == maps.end()) {
                set<int> sub;
                sub.insert(oy);
                maps.insert(pair<int, set<int>>(ox, sub));
            } else {
                itr->second.insert(oy);
            }
        } 
        int tx = x - (dx * min(x / dx, y / dy));
        int ty = y - (dy * min(x / dx, y / dy));    
        int sx = 0, sy = 0;
        bool flag = false;
        if (sx == tx && sy == ty) flag = true;
        itr = maps.find(sx);
        if (itr != maps.end() && (itr->second.find(sy) != itr->second.end())) return false;
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'U') sy++;
            else {
                sx++;
                itr = maps.find(sx);
            }
            if (sx == tx && sy == ty) flag = true;
            if (itr != maps.end() && (itr->second.find(sy) != itr->second.end())) return false;
        }
        return flag;
    }
};
/*TLE
class Solution {
public:
    
    struct cmp {
        bool operator ()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first == b.first && a.second == b.second) return true;
            return false;
        }
    };

    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        set<pair<int, int>> maps;
        for (int i = 0; i < obstacles.size(); i++) {
            maps.insert(pair<int, int>(obstacles[i][0], obstacles[i][1]));
        }
        int dir = 0;
        int xx[2] = {0, 1};
        int yy[2] = {1, 0};
        int curRow = 0;
        int curCol = 0;
        if (curRow > x || curCol > y) return false;
        if (curRow == x && curCol == y) return true;
        while (1) { 
            for (int i = 0; i < command.length(); i++) {
                if (command[i] == 'U') dir = 0;
                else dir = 1;
                curRow += xx[dir];
                curCol += yy[dir];
                if (curRow == x && curCol == y) return true;
                if (curRow > x || curCol > y) return false;
                if (maps.find(pair<int, int>(curRow, curCol)) != maps.end()) return false;
            }
        }

        return false;
    }
};
*/
*/
