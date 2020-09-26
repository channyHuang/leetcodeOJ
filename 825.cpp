class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int len = ages.size();
        if (len <= 1) return 0;
        for (int i = 0; i < len; i++) {
            count[ages[i] * 1.0]++;
        }
        long long res = 0;
        for (map<double, long long>::iterator itr = count.begin(); itr != count.end(); itr++) {
            if (itr->first > 14 && itr->second >= 2) res += (itr->second * (itr->second - 1));
            map<double, long long>::iterator nitr = itr;
            for (nitr++; nitr != count.end(); nitr++) {
                if (nitr->first > 14 && valid(nitr->first, itr->first)) {
                    res += (itr->second * nitr->second);
                }
            }
        }
        return res;
    }

    bool valid(double a, double b) {
        if (b > a) return false;
        if (b <= 0.5 * a + 7) return false;
        if ((b > 100) && (a < 100)) return false;
        return true;
    }
private:
    map<double, long long> count;
};
