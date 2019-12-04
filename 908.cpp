class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
		int len = A.size();
		if (len <= 1) return 0;
		sort(A.begin(), A.end());
		if (A[0] + K >= A[len - 1] - K) return 0;
		return A[len - 1] - K - A[0] - K;
    }
};
