class Solution {
public:
    bool isPathCrossing(string path) {
        
        int x = 0, y = 0;
        maps[x].insert(y);
        for (int i = 0; i < path.length(); i++) {
            switch(path[i]) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                break;
            }
            itr = maps.find(x);
            if (itr == maps.end()) {
                maps[x].insert(y);
                continue;
            }
            if (itr->second.find(y) != itr->second.end()) return true;
            maps[x].insert(y);
        }
        return false;
    }

private:
    map<int, set<int>> maps;
    map<int, set<int>>::iterator itr;
};
