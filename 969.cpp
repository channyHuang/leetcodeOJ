class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int len = A.size();
        vector<int> count;
        vector<int> res;
        count.resize(len + 1);
        for (int i = 0; i < len; i++) {
            count[A[i]] = i;
        }
        for (int i = len; i > 0; i--) {
            if (count[i] == i - 1) continue;
            res.push_back(count[i] + 1);
            res.push_back(i);
            int pos = count[i];
            for (int j = 0; j <= pos / 2; j++) {
                count[A[j]] = pos - j;
                count[A[pos - j]] = j;
                int tmp = A[j];
                A[j] = A[pos - j];
                A[pos - j] = tmp;
            }
            pos = i - 1;
            for (int j = 0; j <= pos / 2; j++) {
                count[A[j]] = pos - j;
                count[A[pos - j]] = j;
                int tmp = A[j];
                A[j] = A[pos - j];
                A[pos - j] = tmp;
            }
        }
        return res;
    }
};
