class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int len = A.size();
        int res = 0;
        sort(A.begin(), A.end());
        int lastCount = 0;
        for (int i = 0; i < len; i++) {
            int stPos = i + 1;
            int endPos = len - 1;
            int need = target - A[i];
            while (stPos < endPos) {
                int sum = A[stPos] + A[endPos];
                if (sum == need) {
                    res = (res + 1) % 1000000007;
                    stPos++;
                } else if (sum > need) {
                    if (A[stPos] > A[endPos]) stPos++;
                    else endPos--;
                } else {
                    if (A[stPos] < A[endPos]) stPos++;
                    else endPos--;
                }
            }
        }
        return res;
    }
};
