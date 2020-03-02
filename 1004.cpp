class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len = A.size();
        if (len <= 0) return 0;
        if (K >= len) return len;
        
        int left = 0;
        int right = 0;
        int res = 0;
        int count = A[0];

        while (right < len) {
            if (count + K >= right - left + 1) {
                if (res < right - left + 1) res = right - left + 1;
                right++;
                if (right >= len) break;
                count += A[right];
            } else {
                count -= A[left];
                left++;
                right++;
                if (right >= len) break;
                count += A[right];
            }
        }
        return res;
    }
};
