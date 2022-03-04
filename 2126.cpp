// 模拟快排

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int len = asteroids.size();
        int stpos = 0;
        int endpos = len - 1;
        long long cur = mass;
        bool flag = true;
        while (stpos < len) {
            while (stpos < len && asteroids[stpos] <= cur) {
                cur += asteroids[stpos];
                stpos++;
            }
            if (stpos >= len) return true;
            while (endpos >= stpos && asteroids[endpos] > cur) {
                endpos--;
            }
            if (endpos < stpos) {
                if (flag) return false;
                endpos = len - 1;
                flag = true;
                continue;
            }
            flag = false;
            int tmp = asteroids[stpos];
            asteroids[stpos] = asteroids[endpos];
            asteroids[endpos] = tmp;
        }
        return true;
    }
};
