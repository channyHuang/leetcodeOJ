class Solution {
public:
    int longestMountain(vector<int>& A) {
        int len = A.size();
        if (len <= 2) return 0;
        int stPos = 0;
        int res = 0;
        while (stPos < len) {
            while (stPos < len - 1 && A[stPos] >= A[stPos + 1]) stPos++;
            if (stPos >= len - 1) break;
            int midPos = stPos + 1;
            if (A[stPos] == A[midPos]) {
                stPos = midPos;
                continue;
            }
            while (midPos < len - 1 && A[midPos] < A[midPos + 1]) midPos++;
            if (midPos >= len - 1) break;
            int endPos = midPos + 1; 
            if (A[endPos] == A[midPos]) {
                stPos = endPos;
                continue;
            }
            while (endPos < len - 1 && A[endPos] > A[endPos + 1]) endPos++;
            if (res < endPos - stPos + 1) res = endPos - stPos + 1;
            stPos = endPos;
        }
        if (res < 2) return 0;
        return res;
    }
};
