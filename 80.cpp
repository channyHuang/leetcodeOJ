class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len;
        int pos = 2;
        int cur = 2;
        while (cur < len) {
            if (nums[cur] == nums[pos - 1] && nums[cur] == nums[pos - 2]) cur++;
            else nums[pos++] = nums[cur++];
        }
        return pos;
    }
};
