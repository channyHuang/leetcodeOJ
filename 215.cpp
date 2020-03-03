class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 1) return nums[0];

        int maxn[len] = {0}; //small root heap
        maxn[0] = nums[0];
        int maxlen = 1;

        for (int i = 1; i < len; i++) {
            if (maxlen < k) {
                maxn[maxlen] = nums[i];
                int idx = maxlen;
                maxlen++;
                up(maxn, maxlen, idx);
            } else if (maxn[0] > nums[i]) {
                 continue;
            } else {
                maxn[0] = nums[i];
                down(maxn, maxlen, 0);
            }
        }
        return maxn[0];
    }

    void up(int maxn[], int len, int idx) {
        if (idx <= 0) return;
        int parent = (idx - 1) / 2; 
        if (maxn[idx] < maxn[parent]) {
            int tmp = maxn[idx];
            maxn[idx] = maxn[parent];
            maxn[parent] = tmp;
            up(maxn, len, parent);
        }
    }

    void down(int maxn[], int len, int idx) {
        int left = idx * 2 + 1;
        if (left >= len) return;
        int right = idx * 2 + 2;
        int targetIdx = left;
        if (right < len) {
            if (maxn[idx] < maxn[left] && maxn[idx] < maxn[right]) return;
            if (maxn[left] > maxn[right]) targetIdx = right;
        }

        if (maxn[targetIdx] < maxn[idx]){
            int tmp = maxn[idx];
            maxn[idx] = maxn[targetIdx];
            maxn[targetIdx] = tmp;
            down(maxn, len, targetIdx);
        }
    }
};
