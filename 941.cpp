class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        if (len < 3) return false;
        if (A[0] >= A[1]) return false;
        if (A[len - 1] >= A[len - 2]) return false;
        int i = 1;
        while (i < len && A[i] > A[i - 1]) i++;
        if (i == len) return false;
        while (i < len && A[i] < A[i - 1]) i++;
        if (i != len) return false;
        return true;
    }
};
