class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();
        vector<int> res;
        res.resize(len);
        for (int i = 0; i < len; i++) res[i] = A[i];
        for (int i = 0; i < len; i++) {
            if (i % 2 == res[i] % 2) {
                continue;
            }
            for (int j = i + 1; j < len; j += 2) {
                if (j % 2 != res[j] % 2) {
                    int tmp = res[i];
                    res[i] = res[j];
                    res[j] = tmp;
                }
            }
        }
        return res;
    }
};
