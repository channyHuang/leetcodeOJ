class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> vec = {a, b, c};
        sort(vec.begin(), vec.end());
        int res = 0;
        while (1) {
            if (vec[0] == 0 && vec[1] == 0) break;
            int cnt = (vec[1] - vec[0] + 1);
            if (cnt > vec[1]) {
                cnt = vec[1];
            }
            vec[1] -= cnt;
            vec[2] -= cnt;
            res += cnt;
            sort(vec.begin(), vec.end());
        }
        return res;
    }
};
