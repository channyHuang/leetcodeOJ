class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            res.push_back(A[i]*A[i]);
            int j = i;
            while (j >= 1 && res[j - 1] > res[j]) {
                int tmp = res[j];
                res[j] = res[j - 1];
                res[j - 1] = tmp;
                j--;
            }
        }
        return res;
    }
};