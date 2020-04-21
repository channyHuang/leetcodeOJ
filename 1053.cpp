class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int len = A.size();
        if (len <= 1) return A;
        int minn = A[len - 1];
        int i;
        for (i = len - 2; i >= 0; i--) {
            if (minn < A[i]) break;
            minn = min(A[i], minn);
        }
        if (i < 0) return A;
        int idx = i + 1;
        while (idx < len && A[i] <= A[idx]) idx++;
        int tmp = idx + 1;
        while (tmp < len) {
            if (A[tmp] >= A[i]) tmp++;
            else if (A[tmp] > A[idx]) idx = tmp++;
            else tmp++;
        }
        tmp = A[i];
        A[i] = A[idx];
        A[idx] = tmp;
        return A;
    }
};