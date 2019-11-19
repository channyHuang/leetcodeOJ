class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return (nums[0] > nums[1] ? nums[0] : nums[1]);

        int value[nums.size()] = {0};
        bool gets[nums.size()] = {0};
        value[0] = nums[0];
        gets[0] = 1;
        value[1] = (nums[0] > nums[1] ? nums[0] : nums[1]);
        gets[1] = {nums[0] > nums[1] ? 0 : 1};

        int res = (value[0] > value[1] ? value[0] : value[1]);
        for (int i = 2; i < nums.size(); i++) {
            int a = value[i - 2] + nums[i];
            int b = gets[i - 1] ? value[i - 1] : value[i - 1] + nums[i];
            if (a > b) {
                value[i] = a;
                gets[i] = 1;
            } else {
                value[i] = b;
                if (!gets[i - 1]) gets[i] = 1;
            }

            if (value[i] > res) res = value[i];
        }
        
        return res;
    }
};
