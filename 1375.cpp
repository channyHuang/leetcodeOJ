class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int len = light.size();
        if (len == 1) return 1;
        set<int> sets;
        int res = 1;
        int lastMax = 0;
        for (int i = 1; i <= len; i++) {
            sets.insert(i);
        }
        for (int i = 0; i < len - 1; i++) {
            bool flag = true;
            set<int>::iterator itr = sets.find(light[i]);
            if (itr != sets.begin()) flag = false;
            sets.erase(itr);
            if (lastMax < light[i]) lastMax = light[i];
            if (flag && *sets.begin() > lastMax) res++;          
        }
        return res;
    }
};
