class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int len = A.size();
        int add = 0;
        vector<int> res;
        int pos = 0;
        if (len <= 0) return res;
        
        for (int i = len - 1; i >= 0; i--) {
            res.push_back(A[i] + K % 10 + add);
            if (res[pos] >= 10) {
                res[pos] %= 10;
                add = 1;
            } else {
                add = 0;
            }
            pos++;
            K /= 10;
        }

        while (K) {
            res.push_back(add + K % 10);
            K /= 10;
            if (res[pos] >= 10) {
                res[pos] %= 10;
                add = 1;
            } else {
                add = 0;
            }
            pos++;
        }

        if (add) {
            res.push_back(1); 
            pos++;
        }
        
        int tmp;
        for (int i = 0; i < pos / 2; i++) {
            tmp = res[i];
            res[i] = res[pos - i - 1];
            res[pos - i - 1] = tmp;
        }

        return res;
    }
};
