class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {   
        int len = nums.size();
        int res = 0;
        vector<int> sum(len, 0);
        int curSum = 0;
        unordered_map<int, int> maps;
        unordered_map<int, int>::iterator itr;
        int stPos = 0;
        for (int i = 0; i < len; i++) {
            itr = maps.find(nums[i]);
            sum[i] = (i > 0 ? sum[i - 1] : 0) + nums[i];
            if (itr == maps.end() || itr->second < stPos) {
                curSum += nums[i];
                res = max(res, curSum);
                maps[nums[i]] = i;
            } else {
                stPos = itr->second + 1;
                res = max(res, curSum);
                curSum = sum[i] - sum[itr->second];
                maps[nums[i]] = i;
            }            
        }
        return res;
    }
};
