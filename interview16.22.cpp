class Solution {
public:
    vector<string> printKMoves(int K) {
        vector<string> res;
        if (K == 0) {
            res.push_back("R");
            return res;
        }
        int curx = 0, cury = 0;
        char dirch = 'R';
        int dir = 0;
        for (int i = 1; i <= K; ++i) {
            auto itry = maps.find(curx);
            if (itry == maps.end()) {//white
                maps[curx].insert(cury);

                dirch = getDir(dir);
                curx += steps[dir][0];
                cury += steps[dir][1];
                
                minx = std::min(curx, minx);
                miny = std::min(cury, miny);
                maxx = std::max(curx, maxx);
                maxy = std::max(cury, maxy);
            } else {
                auto itr = itry->second.find(cury);
                if (itr == itry->second.end()) {
                    maps[curx].insert(cury);

                    dirch = getDir(dir);
                    curx += steps[dir][0];
                    cury += steps[dir][1];
                    
                    minx = std::min(curx, minx);
                    miny = std::min(cury, miny);
                    maxx = std::max(curx, maxx);
                    maxy = std::max(cury, maxy);
                } else {//black
                    itry->second.erase(itr);
                    if (itry->second.size() <= 0) {
                        maps.erase(itry);
                    }

                    dirch = getDir(dir, false);
                    curx += steps[dir][0];
                    cury += steps[dir][1];

                    minx = std::min(curx, minx);
                    miny = std::min(cury, miny);
                    maxx = std::max(curx, maxx);
                    maxy = std::max(cury, maxy);
                }
            }
        }
        int row = (maxy - miny + 1);
        int col = (maxx - minx + 1);
        for (int i = 0; i < row; ++i) {
            string str(col, '_');
            res.push_back(str);
        }

        for (auto itry = maps.begin(); itry != maps.end(); itry++) {
            auto itr = itry->second.begin();
            for (auto itr = itry->second.begin(); itr != itry->second.end(); itr++) {
                res[maxy - (*itr)][itry->first - minx] = 'X';
            }
        }
        res[maxy - cury][curx - minx] = dirch;
        return res;
    }

    char getDir(int &curDir, bool isWhite = true) {
        curDir = (isWhite ? (curDir + 1) % 4 : (curDir + 3) % 4);
        return dir[curDir];
    }

private:
    int minx = 0, maxx = 0;
    int miny = 0, maxy = 0;
    //dir 0:R 1:D 2:L 3:U
    vector<char> dir = {'R', 'D', 'L', 'U'};
    vector<vector<int>> steps = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    unordered_map<int, unordered_set<int> > maps;
};
