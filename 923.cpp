class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int len = A.size();
        long long res = 0;
        sort(A.begin(), A.end());
        vector<long long> count;
        int newlen = 1;
        count.push_back(1);
        for (int i = 1; i < len; i++) {
            if (A[i] == A[newlen - 1]) {
                count[newlen - 1]++;
            } else {
                A[newlen++] = A[i];
                count.push_back(1);
            }
        }
        //3 different
        for (int i = 0; i < newlen; i++) {
            for (int k = newlen - 1; k > i; k--) {
                long long num = target - A[i] - A[k];
                int idx = findTarget(A, i + 1, k - 1, num);
                if (idx == -1) continue;
                res += (count[i] * count[k] * count[idx]);
                res %= maxn;
            }
        }
        //3 same
        if (target % 3 == 0) {
            int idx = findTarget(A, 0, newlen - 1, target / 3);
            if (idx != -1 && count[idx] >= 3) {
                res += (count[idx] * (count[idx] - 1) * (count[idx] - 2) / 6);
                res %= maxn;
            }
        }
        //2 same
        for (int i = 0; i < newlen; i++) {
            if (count[i] < 2) continue;
            long long num = target - A[i] - A[i];
            int idx = findTarget(A, 0, newlen - 1, num);
            if (idx == -1 || idx == i) continue;
            res += (count[i] * (count[i] - 1) / 2 * count[idx]);
            res %= maxn;
        }
        return res;
    }

    int findTarget(vector<int>& A, int stPos, int endPos, long long target) {
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (A[midPos] == target) return midPos;
            else if (A[midPos] < target) {
                stPos = midPos + 1;
            } else {
                endPos = midPos - 1;
            }
        }
        return -1;
    }

private:
    long long maxn = 1000000007;
};
