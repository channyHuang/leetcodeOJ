class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        if (len <= 2) return true;
        bool up = true;
        int i = 1;
        while (i < len && A[i] == A[i - 1]) i++;
        if (i == len) return true;
        else if (A[i] < A[i - 1]) up = false;
        for (; i < len; i++) {
            if (up && A[i] < A[i - 1]) return false;
            else if (!up && A[i] > A[i - 1]) return false;
        }
        return true;
    }
};
