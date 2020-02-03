class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int num = n / 2;
        for (int i = 1; i <= num; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        if (n & 1) {
            res.push_back(0);          
        }
        return res;
    }
};