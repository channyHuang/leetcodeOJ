class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 9) continue;
            else if (nums[i] <= 99) res++;
            else if (nums[i] <= 999) continue;
            else if (nums[i] <= 9999) res++;
            else if (nums[i] <= 99999) continue;
        }
        return res;
    }
};