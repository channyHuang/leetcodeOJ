class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> res;
        for (int i = 0; i < A.size(); i++) {
            if (res.find(A[i]) != res.end()) return A[i];
            res.insert(A[i]);
        }
        return 0;
    }
};
