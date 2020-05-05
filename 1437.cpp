class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return true;
        int last = -1;
        int i;
        for (i = 0; i < len; i++) {
            if (nums[i] == 1) {
                last = i;
                break;
            }
        }
        for (i++; i < len; i++) {
            if (nums[i] == 1) {
                if (i - last - 1 < k) return false;
                last = i;
            }
        }
        return true;
    }
};
