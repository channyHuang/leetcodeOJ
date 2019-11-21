class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        int sum = (1 + len) * len / 2;
        bool appear[len + 2] = {false};
        vector<int> res;
        for (int i = 0; i < len; i++) {
            appear[nums[i]] = true;
            sum -= nums[i];
        }

        int target = 0;
        for (target = 1; target <= len; target++) {
            if (!appear[target]) break;
        }
        //sum = target - repeat
        res.push_back(target - sum);
        res.push_back(target);
        return res;
    }
};
