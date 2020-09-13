class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int len = nums.size();
        maps.clear();
        maps[0] = -1;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            unordered_map<int, int>::iterator uitr = maps.find(sum - target);
            if (uitr != maps.end()) {
                res++;
                maps.clear();
                maps[0] = -1;
                sum = 0;
            } else {
                maps[sum] = i;
            }
        }
        
        return res;
    }

private:
    unordered_map<int, int> maps;
    int res;
};
