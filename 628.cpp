class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len < 3) return 0;
        //all positive or neigtive
        if (nums[0] >= 0 || nums[len - 1] < 0) {
            return nums[len - 1] * nums[len - 2] * nums[len - 3];
        } 
        //at least 2 negitive
        if (nums[0] < 0 && nums[1] < 0) {
            int negi = nums[0] * nums[1] * nums[len - 1];
            int posi = nums[len - 1] * nums[len - 2] * nums[len - 3];
            return negi > posi ? negi : posi; 
        }
        return nums[len - 1] * nums[len - 2] * nums[len - 3];
    }
};
