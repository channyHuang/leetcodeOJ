class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (maxFactor(j, i) == 1) {
                    res.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return res;
    }

    int maxFactor(int a, int b) {
        if (a == b) return a;
        int tmp = a;
        if (a < b) {
            a = b;
            b = tmp;
        }
        while (b) {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
};
