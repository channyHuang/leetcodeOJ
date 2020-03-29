class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int len = trips.size();
        if (len <= 0) return true;
        if (len == 1) return (trips[0][0] <= capacity);
        sort(trips.begin(), trips.end(), cmp);
        if (capacity < trips[0][0]) return false;
        int curCap = trips[0][0];
        int curLoc = trips[0][1];
        int pos = 0;
        vector<vector<int>> curTrips;
        curTrips.push_back(trips[0]);
        for (int i = 1; i < len; i++) {
            if (trips[i][1] == curLoc) {
                curCap += trips[i][0];
                if (curCap > capacity) return false;
                curTrips.push_back(trips[i]);
                sort(curTrips.begin() + pos, curTrips.end(), cmpEnd);
                continue;
            }
            curLoc = trips[i][1];
            for (; pos < curTrips.size(); pos++) {
                if (curTrips[pos][2] > curLoc) break;
                curCap -= curTrips[pos][0];
            }
            curCap += trips[i][0];
            if (curCap > capacity) {
                return false;
            }
            curTrips.push_back(trips[i]);
            sort(curTrips.begin() + pos, curTrips.end(), cmpEnd);           
        }
        return true;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            if (a[2] == b[2]) return a[0] > b[0];
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }

    static bool cmpEnd(const vector<int>& a, const vector<int>& b) {
        if (a[2] == b[2]) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        }
        return a[2] < b[2];
    }
};
