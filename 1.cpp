class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool flag = false;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    //if (target % 2 == 0 && nums[j] == target / 2) continue;
                    flag = true;
                    res.push_back(i);
                    res.push_back(j);
                }
            }
            if (flag) break;
        }
        return res;
    }
};

/*
 * 说好的“不能重复利用这个数组中同样的元素”呢？？？
 */
