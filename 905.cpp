class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        int len = A.size();
        res.resize(len);
        int stPos = 0, endPos = len - 1;
        while (stPos <= endPos) {
            while (stPos <= endPos && A[stPos] % 2 == 0) {
                res[stPos] = A[stPos];
                stPos++;
            }
            while (stPos <= endPos && A[endPos] % 2 == 1) {
                res[endPos] = A[endPos];
                endPos--;
            }
            if (stPos > endPos) break;
            res[stPos] = A[endPos];
            res[endPos] = A[stPos];
            stPos++;
            endPos--;
        }
        return res;
    }
};
