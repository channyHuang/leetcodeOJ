class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // small root heap
        int len = nums.size();
        vector<int> heaps(1, 0);
        curlen = 1;
        for (int i = 1; i < len; ++i) {
            if (curlen < k) {
                heaps.push_back(i);
                curlen++;
                up(nums, heaps, curlen - 1);
            } else {
                int cmp = compare(nums[i], nums[heaps[0]]);
                if (cmp != -1) continue;
                heaps[0] = i;
                down(nums, heaps, 0);
            }
        }
        return nums[heaps[0]];
    }
    // 1: a < b; 0: a = b; -1: a > b
    int compare(const string& a, const string& b) {
        int alen = a.length();
        int blen = b.length();

        if (alen > blen) return -1;
        if (alen < blen) return 1;
        for (int i = 0; i < alen; ++i) {
            if (a[i] > b[i]) return -1;
            if (a[i] < b[i]) return 1;
        }
        return 0;
    }

    void down(vector<string>& nums, vector<int>& heaps, int idx) {
        int childidx = ((idx << 1) + 2);
        if (childidx - 1 >= curlen) return;
        if (childidx == curlen) {
            childidx -= 1;
            int cmp = compare(nums[heaps[childidx]], nums[heaps[idx]]);
            if (cmp != 1) return;
            int tmp = heaps[idx];
            heaps[idx] = heaps[childidx];
            heaps[childidx] = tmp;
            return;
        }
        int cmp = compare(nums[heaps[childidx]], nums[heaps[childidx - 1]]);
        if (cmp == -1) childidx -= 1;
        cmp = compare(nums[heaps[idx]], nums[heaps[childidx]]);
        if (cmp != -1) return;
        int tmp = heaps[idx];
        heaps[idx] = heaps[childidx];
        heaps[childidx] = tmp;
        down(nums, heaps, childidx);
    }

    void up(vector<string>& nums, vector<int>& heaps, int idx) {
        if (idx <= 0) return;
        int parentidx = ((idx - 1) >> 1);
        int cmp = compare(nums[heaps[parentidx]], nums[heaps[idx]]);
        if (cmp != -1) return;
        int tmp = heaps[idx];
        heaps[idx] = heaps[parentidx];
        heaps[parentidx] = tmp;
        up(nums, heaps, parentidx);
    }

private:
    int curlen = 1;
};
