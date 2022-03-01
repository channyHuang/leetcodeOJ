// 只有当一轮指令后不在原点且方向保持向北才没有环

class Solution {
public:
    bool isRobotBounded(string instructions) {
        dir = 0;     
        int curx = 0, cury = 0;  
        int len = instructions.length();
        unordered_map<int, unordered_set<int>> maps;
        maps[curx].insert(cury);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < len; ++j) {
                if (instructions[j] == 'G') {
                    curx += steps[dir][0];
                    cury += steps[dir][1];

                    auto itr = maps.find(curx);
                    if (itr == maps.end()) {
                        maps[curx].insert(cury);
                    } else {
                        auto sitr = itr->second.find(cury);
                        if (sitr == itr->second.end()) {
                            maps[curx].insert(cury);
                        }
                    }

                } else {
                    changeDir(instructions[j]);
                }
            }
            if (curx == 0 && cury == 0) return true;
        }
        return false;
    }

    void changeDir(char c) {
        switch(c) {
        case 'L':
            dir--;
            if (dir < 0) dir = 3;
            break;
        case 'R':
            dir++;
            if (dir >= 4) dir = 0;
            break;
        default:
            break;
        }
    }

private:
    vector<vector<int>> steps = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir;
};
