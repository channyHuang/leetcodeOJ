class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int len = gain.size();
        int cur = 0;
        for (int i = 0; i < len; i++) {
            cur += gain[i];
            res = max(res, cur);
        }
        return res;
    }
};
