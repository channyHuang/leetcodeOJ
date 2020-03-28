class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int finsum = nums[0] + nums[1] + nums[2];
        int maxdif = abs(finsum - target);
        bool stAdd = false;
        for (int i = 0; i < len; i++) {
            int stPos = i + 1, endPos = len - 1;
            while (stPos < endPos) {
                int sum = nums[i] + nums[stPos] + nums[endPos];
                if (sum == target) return sum;
                if (abs(sum - target) < maxdif) {
                    maxdif = abs(sum - target);
                    finsum = sum;
                }
                if (sum > target) endPos--;
                else stPos++;
            }
        }
        
        return finsum;
    }
};
