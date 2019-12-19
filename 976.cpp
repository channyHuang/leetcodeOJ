class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int len = A.size();
        if (len <= 2) return 0;
        sort(A.begin(), A.end());
        int res = 0;
        int sum = 0;
        for (int i = len - 1; i >= 2; i--) {
            if (A[i] < res) break;
            for (int j = i - 1; j >= 1; j--) {
                sum = A[i] + A[j];
                if (sum < res) break;
                for (int k = j - 1; k >= 0; k--) {
                    if (sum + A[k] < res) break;
                    if (A[j] + A[k] <= A[i]) break;
                    if (res < sum + A[k]) res = sum + A[k];
                } 
            }
        }
        return res;
    }
};
