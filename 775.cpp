class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int len = A.size();
        int maxn = A[0];
        for (int j = 2; j < len; j++) {
            maxn = max(maxn, A[j - 2]);
            if (maxn > A[j]) return false;           
        }
        return true;
    }
};
