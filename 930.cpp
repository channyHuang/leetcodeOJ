class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int len = A.size();
        if (len < S) return 0;
        int res = 0;
        if (S == 0) {
            int count = 0;
            for (int i = 0; i < len; i++) {
                if (A[i]) {
                    count = 0;
                    continue;
                }
                count++;
                res += count;
            }
            return res;
        }

        vector<int> index;
        index.push_back(-1);
        int count = 1;
        for (int i = 0; i < len; i++) {
            if (A[i]) {
                index.push_back(i);
                count++;
                if (count > S + 1) {
                    res += (index[count - 1] - index[count - 1 - 1]) * (index[count - 1 - S] - index[count - 1 - S - 1]);
                }
            }
        }
        index.push_back(len);
        count++;
        if (count > S + 1) {
            res += (index[count - 1] - index[count - 1 - 1]) * (index[count - 1 - S] - index[count - 1 - S - 1]);
        }

        return res;
    }
};
