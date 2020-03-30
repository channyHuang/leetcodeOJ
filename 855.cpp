class ExamRoom {
public:
    ExamRoom(int N) {
        count = N;
    }
    
    int seat() {
        if (maps.empty()) {
            maps[0] = 1;
            return 0;
        }
        int res = -1;
        map<int, int>::iterator itr = maps.begin();
        map<int, int>::iterator preItr;
        int maxDis = 0;
        if (maps.find(0) == maps.end()) {
            maxDis = itr->first;
            res = 0;
        }
        
        preItr = maps.begin();
        itr++;
        for (; itr != maps.end(); itr++) {
            int stPos = preItr->first + 1;
            int endPos = itr->first - 1;
            int tmpres = (stPos + endPos) / 2;
            if (tmpres - stPos + 1 > maxDis) {
                maxDis = tmpres - stPos + 1;
                res = tmpres;
            }
            ++preItr;
        }
        itr = maps.end();
        itr--;
        if (count - 1 - itr->first > maxDis) {
            maxDis = count - 1 - itr->first;
            res = count - 1;
        }
        maps.insert(pair<int, int>(res, 1));
        return res;
    }
    
    void leave(int p) {
        map<int, int>::iterator itr = maps.find(p);
        //if (itr == maps.end()) return;
        maps.erase(itr);
    }

private:
    int count;
    map<int, int> maps;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
