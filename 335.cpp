class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int len = x.size();
        for (int i = 3; i < len; i++) {
            //cross in i with i - 3
            if (x[i] >= x[i - 2] && x[i - 3] >= x[i - 1]) return true;
            //cross in i with i - 4
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
            //cross in i with i - 5
            if (i >= 5 && x[i] + x[i - 4] >= x[i - 2] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 2] >= x[i - 4] && x[i - 1] <= x[i - 3]) return true;
        }
        return false;
    }
};