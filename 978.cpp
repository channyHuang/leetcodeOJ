class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int len = A.size();
        if (len <= 1) return len;
        if (len == 2) return (A[0] == A[1] ? 1 : 2);
        int i;
        for (i = 1; i < len; i++) {
            if (A[i] != A[0]) break;
        }
        if (i == len) return 1;
        
        int res = 2;
        int left = 0;
        int right = 1;
        while (right < len) {
            if (A[right] == A[right - 1]) {
                left = right;
                right = left + 1;
                continue;
            } 
            if (right - left == 1) {
                right++;
                continue;
            }
            if ((A[right - 1] > A[right] && A[right - 1] > A[right - 2]) ||
                 (A[right - 1] < A[right] && A[right - 1] < A[right - 2])) {
                if (res < right - left + 1) res = right - left + 1;
                right++;
            } else {
                left = right - 1;
            }
        }

        return res;
    }
};
