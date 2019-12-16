class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> res;
        for (int i = 0; i < A.size(); i++) {
            num = (num << 1) + A[i];
            num %= 10;
            if (num % 5 == 0) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
