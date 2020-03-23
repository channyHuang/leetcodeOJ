class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int len = A.size();
        if (len <= 0) return 0;
        sort(A.begin(), A.end());
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (A[i] > A[i - 1]) continue;
            res += (A[i - 1] - A[i] + 1);
            A[i] = A[i - 1] + 1; 
        }
        return res;
    }
};
