class Solution {
public:
    int countTriplets(vector<int>& A) {
        int len = pow(2, 16);
        int lena = A.size();
        vector<int> twoAnd(len, 0);
        vector<int> one(len, 0);
        for (int i = 0; i < lena; i++) {
            twoAnd[A[i]]++;
            for (int j = i + 1; j < lena; j++) {
                int idx = (A[i] & A[j]);
                twoAnd[idx] += 2;
            }

            for (int j = 0; j < len; j++) {
                if ((A[i] & j) == 0) one[j]++;
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) res += twoAnd[i] * one[i];
        return res;
    }
};
