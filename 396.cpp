class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long len = A.size();
        if (len <= 0) return 0;
        long long dp[len];
        long long sum = A[0];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < len; i++) {
            dp[0] += (i * A[i]);
            sum += A[i];
        }
        long long res = dp[0];
        for (int i = 1; i < len; i++) {
            dp[i] = dp[i - 1] + sum - len * A[len - i];
            res = max(res, dp[i]);
        }
        return res;
    }
};
/* 直接算，用堆，都会超时哦
class Solution {
public:
    class Node {
    public:
        long long sum;
        int stPos;
        int curIdx;
        Node (long long _sum = 0, int _pos = 0, int _idx = 0) {
            sum = _sum;
            stPos = _pos;
            curIdx = _idx;
        }
    };
    
    int maxRotateFunction(vector<int>& A) {
        int len = A.size();
        if (len <= 0) return 0;
        vector<Node> sums;
        for (int i = 0; i < len; i++) {
            sums.push_back(Node(A[i], (i + len - 1) % len, 2));
        }
        sort(sums.begin(), sums.end(), cmp);
        while (sums[0].curIdx < len) {
            sums[0].sum += (sums[0].curIdx * A[(sums[0].stPos + sums[0].curIdx) % len]);
            sums[0].curIdx++;
            int idx = 0;
            int nextIdx = 2 * idx + 1;
            while (nextIdx < len) {
                if (nextIdx + 1 < len && sums[nextIdx + 1].sum < sums[nextIdx].sum) nextIdx++;
                if (sums[idx].sum > sums[nextIdx].sum) {
                    Node tmp = sums[idx];
                    sums[idx] = sums[nextIdx];
                    sums[nextIdx] = tmp;
                    idx = nextIdx;
                    nextIdx = 2 * idx + 1;
                } else break;
            }
        }
        return sums[0].sum;
    }

    static bool cmp(Node& a, Node& b) {
        if (a.sum == b.sum && a.curIdx == b.curIdx) return a.stPos < b.stPos;
        if (a.sum == b.sum) return a.curIdx < b.curIdx;
        return a.sum < b.sum;
    }
};
*/
