class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len;
        int maxlen = 1;
        bool used[len];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < len; i++) {
            if (used[i]) continue;
            int pos = i;
            int count = 0;
            while (!used[pos]) {
                used[pos] = true;
                pos = nums[pos];
                count++;
            }
            if (maxlen < count) maxlen = count;
        }
        return maxlen;
    }
};
