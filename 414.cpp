class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int res[3] = {0};
        int len = nums.size();
        if (len <= 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        res[0] = nums[0];
          
        int i = 1;
        while (i < len && nums[i] == res[0]) i++;
        if (i >= len) return res[0];
        res[1] = nums[i++];

        while (i < len && (nums[i] == res[0] || nums[i] == res[1])) i++;
        if (i >= len) return res[0] > res[1] ? res[0] : res[1];
        res[2] = nums[i++];

        int minIndex = 0;
        if (res[1] < res[minIndex]) minIndex = 1;
        if (res[2] < res[minIndex]) minIndex = 2;

        for (; i < len; i++) {
            if (nums[i] > res[minIndex] && nums[i] != res[0] && nums[i] != res[1] && nums[i] != res[2]) {
                res[minIndex] = nums[i];
                minIndex = 0;
                if (res[1] < res[minIndex]) minIndex = 1;
                if (res[2] < res[minIndex]) minIndex = 2;
            }
        }
        return res[minIndex];
    }
};
