class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0;
        int third = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            once = ~third & (once ^ nums[i]);
            third = ~once & (third ^ nums[i]);
        }
        return once;
    }
};
