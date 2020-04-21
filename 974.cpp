class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> lefts[10001];
        int res = 0;
        int len = A.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += A[i];
            int hash = sum % K;
            while (hash < 0) hash = (hash + K) % K;
            res += lefts[hash].size();
            if (hash == 0) res++;
            lefts[hash].push_back(i);
        }
        return res;
    }
};
