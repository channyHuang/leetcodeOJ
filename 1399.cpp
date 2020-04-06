class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int tmp = i;
            while (tmp) {
                sum += (tmp % 10);
                tmp /= 10;
            }
            itr = maps.find(sum);
            if (itr == maps.end()) {
                maps.insert(pair<int, int>(sum, 1));
            } else itr->second++;
        }
        int maxn = 0;
        int res = 0;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second > maxn) {
                maxn = itr->second;
                res = 1;
            } else if (itr->second == maxn) {
                res++;
            }
        }
        return res;
    }
};
