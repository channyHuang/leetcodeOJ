class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return nums;
        int count[2] = {1, 0};
        int select[2] = {nums[0]};
        int i;
        for (i = 1; i < len; i++) {
            if (nums[i] == nums[0]) count[0]++;
            else {
                select[1] = nums[i];
                count[1]++;
                break;
            }
        }
        for (i++; i < len; i++) {
            if (nums[i] == select[0]) count[0]++;
            else if (nums[i] == select[1]) count[1]++;
            else {
                if (count[0] == 0) {
                    select[0] = nums[i];
                    count[0]++;
                } else if (count[1] == 0) {
                    select[1] = nums[i];
                    count[1]++;
                } else {
                    count[0]--;
                    count[1]--;
                }
            }
        }
        count[0] = 0;
        count[1] = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == select[0]) count[0]++;
            else if (nums[i] == select[1]) count[1]++;
        }
        vector<int> res;
        if (count[0] > len / 3) res.push_back(select[0]);
        if (count[1] > len / 3) res.push_back(select[1]);
        return res;
    }
};
