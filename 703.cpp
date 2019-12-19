class KthLargest {
public:
    vector<int> kth;
    int count;
    int numk;

    KthLargest(int k, vector<int>& nums) {
        int len = nums.size();
        kth.resize(k);
        numk = k;
        count = k - 1;
        if (len <= 0) return;

        sort(nums.begin(), nums.end());
        for (int i = len - 1; i >= 0; i--) {
            kth[count--] = nums[i];
            if (count < 0) break;
        }
    }
    
    int add(int val) {
        if (count < 0) {
            if (val <= kth[0]) return kth[0];
        }
        kth[0] = val;
        count = -1;
        int pos = 0;
        while (1) {
            int next = (pos << 1) + 2;
            if (next >= numk) {
                next = (pos << 1) + 1;
                if (next >= numk) break;
                if (kth[next] < kth[pos]) {
                    int tmp = kth[pos];
                    kth[pos] = kth[next];
                    kth[next] = tmp;
                    pos = next;
                } else break;
            } else {
                if (kth[next] < kth[pos]) {
                    if (kth[next - 1] < kth[next]) {
                        int tmp = kth[pos];
                        kth[pos] = kth[next - 1];
                        kth[next - 1] = tmp;
                        pos = next - 1;
                    } else {
                        int tmp = kth[pos];
                        kth[pos] = kth[next];
                        kth[next] = tmp;
                        pos = next;
                    }
                } else {
                    next = (pos << 1) + 1;
                    if (kth[next] < kth[pos]) {
                        int tmp = kth[pos];
                        kth[pos] = kth[next];
                        kth[next] = tmp;
                        pos = next;
                    } else break;
                }
            }
        }
        return kth[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
