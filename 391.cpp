class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int len = rectangles.size();
        if (len <= 1) return true;
        
        double area = 0;
        int minx = rectangles[0][0];
        int miny = rectangles[0][1];
        int maxx = rectangles[0][2];
        int maxy = rectangles[0][3];
        for (int i = 0; i < len; i++) {
            area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
            minx = min(minx, rectangles[i][0]);
            miny = min(miny, rectangles[i][1]);
            maxx = max(maxx, rectangles[i][2]);
            maxy = max(maxy, rectangles[i][3]);
            update(rectangles[i][0], rectangles[i][1]);
            update(rectangles[i][0], rectangles[i][3]);
            update(rectangles[i][2], rectangles[i][3]);
            update(rectangles[i][2], rectangles[i][1]);
        }
        if ((maxy - miny) * (maxx - minx) != area) return false;
        if (sets.size() != 4) return false;
        itr = sets.begin();
        int minxx = (*itr).first;
        int maxxx = (*itr).first;
        int minyy = (*itr).second;
        int maxyy = (*itr).second;
        for (itr = sets.begin(); itr != sets.end(); itr++) {
            minxx = min(minxx, (*itr).first);
            maxxx = max(maxxx, (*itr).first);
            minyy = min(minyy, (*itr).second);
            maxyy = max(maxyy, (*itr).second);
        }
        if (minxx != minx || minyy != miny || maxxx != maxx || maxyy != maxy) return false;
        return true;
    }

    void update(int x, int y) {
        itr = sets.find(pair<int, int>(x, y));
        if (itr == sets.end()) {
            sets.insert(pair<int, int>(x, y));
        } else {
            sets.erase(itr);
        }
    }

private:
    set<pair<int, int>> sets;
    set<pair<int, int>>::iterator itr;
};
