class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int stPos = 1, endPos = A.size() - 1;
        int res = 0;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (A[midPos] > A[midPos - 1] && A[midPos] > A[midPos + 1]) return midPos;
            else if (A[midPos] < A[midPos + 1]) stPos = midPos + 1;
            else endPos = midPos - 1;
        }
        return res;
    }
};
