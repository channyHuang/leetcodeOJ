class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        A.insert(A.begin(), 0);
        int len = A.size();
        vector<int> presum(len, A[0]);
        for (int i = 1; i < len; i++) {
            presum[i] = presum[i - 1] + A[i];
        }
        deque<int> qu;
        for (int i = 0; i < len; i++) {
            while (!qu.empty() && presum[qu.front()] > presum[i]) {
                qu.pop_front();
            }
            while (!qu.empty() && presum[i] - presum[qu.back()] >= K) {
                res = min(res, i - qu.back());
                qu.pop_back();
            }
            qu.push_front(i);
        }
        return (res > len ? -1 : res);
    }

private:
    int res = INT_MAX;
};
