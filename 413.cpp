class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len < 3) return 0;
        int res = 0;
        int stPos = 0;
        int lastPos = 2;
        while (stPos < len) {
            while (lastPos < len && A[lastPos] - A[lastPos - 1] == A[lastPos - 1] - A[lastPos - 2]) lastPos++;
            int tmpLen = lastPos - stPos;
            if (tmpLen < 3) {
                stPos = lastPos - 1;
                lastPos = stPos + 2;
                continue;
            }            
            res += (tmpLen - 2 + 1) * (tmpLen - 3 + 1) / 2;
            stPos = lastPos - 1;
            lastPos = stPos + 2; 
        }
        return res;
    }
};
