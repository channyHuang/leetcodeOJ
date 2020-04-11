class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums;
        int len = primes.size();
        if (len == 0) return 0;
        nums.push_back(1);
        vector<pair<int, int>> heap;
        set<int> sets;
        sets.insert(1);
        for (int i = 0; i < len; i++) {
            heap.push_back(pair<int, int>(i, 0));
            sets.insert(primes[heap[i].first] * nums[heap[i].second]);
        }

        while (nums.size() < n) {
            nums.push_back(primes[heap[0].first] * nums[heap[0].second]);
            heap[0].second++;
            while (sets.find(primes[heap[0].first] * nums[heap[0].second]) != sets.end()) heap[0].second++;
            sets.insert(primes[heap[0].first] * nums[heap[0].second]);
            int idx = 0;
            int pidx = idx * 2 + 1;
            while (pidx < len) {
                if (pidx + 1 < len && primes[heap[pidx + 1].first] * nums[heap[pidx + 1].second] < primes[heap[pidx].first] * nums[heap[pidx].second]) {
                    pidx++;
                }
                if ((primes[heap[idx].first] * nums[heap[idx].second]) > (primes[heap[pidx].first] * nums[heap[pidx].second])) {
                    pair<int, int> tmp = heap[idx];
                    heap[idx] = heap[pidx];
                    heap[pidx] = tmp;
                    idx = pidx;
                    pidx = idx * 2 + 1;
                } else break;
            }
        }
        return nums[n - 1];
    }
};
