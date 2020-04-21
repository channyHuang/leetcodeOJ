class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int len = A.size();
        if (len <= 0) return true;
        sort(A.begin(), A.end());
        queue<int> qu[3];
        for (int i = 0; i < len; i++) {
            if (A[i] < 0) {
                if (!qu[0].empty()) {
                    int tmp = qu[0].front();
                    if (A[i] * 2 == tmp) qu[0].pop();
                    else if (A[i] * 2 > tmp) return false;
                    else {
                        qu[0].push(A[i]);
                    }
                } else qu[0].push(A[i]);
            } else if (A[i] == 0) {
                if (!qu[1].empty()) {
                    qu[1].pop();
                } else qu[1].push(A[i]);
            } else {
                if (!qu[2].empty()) {
                    int tmp = qu[2].front();
                    if (tmp * 2 == A[i]) qu[2].pop();
                    else if (tmp * 2 < A[i]) return false;
                    else {
                        qu[2].push(A[i]);
                    }
                } else qu[2].push(A[i]);
            }
        }
        if (!qu[0].empty() || !qu[1].empty() || !qu[2].empty()) return false;
        return true;
    }
};
