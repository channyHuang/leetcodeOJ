
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
