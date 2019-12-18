class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int curSum = 0;
        for (int i = 0; i < A.size(); i++) {
            if ((A[i] & 1) == 0) curSum += A[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            if ((A[queries[i][1]] & 1) == 0) {
                if ((queries[i][0] & 1) == 0) {
                    curSum += queries[i][0];
                } else {
                    curSum -= A[queries[i][1]];
                }
            } else {
                if ((queries[i][0] & 1) != 0) curSum += A[queries[i][1]] + queries[i][0];
            }
            A[queries[i][1]] += queries[i][0];
            res.push_back(curSum);
        }
        return res;
    }
};
