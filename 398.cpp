class Solution {
public:
    vector<int> num;

    Solution(vector<int>& nums) {
        num = nums;
    }
    
    int pick(int target) {
        int len = num.size();
        int count = 0;
        vector<int> index;
        for (int i = 0; i < len; i++) {
            if (num[i] == target) {
                index.push_back(i);
            }
        }
        int idx = rand() % index.size();
        return index[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
