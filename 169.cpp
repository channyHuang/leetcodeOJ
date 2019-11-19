class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() <= 2) return nums[0];
        int count = nums.size() / 2;
        map<int, int> calc;
        std::map<int, int>::iterator itr;
        for (int i = 0; i < nums.size(); i++) {
            if ((itr = calc.find(nums[i])) == calc.end()) {
                calc.insert(std::make_pair(nums[i], 1));
            } else {
                itr->second++;
                if (itr->second > count) return itr->first;
            }
        }
        return 0;
    }
};

