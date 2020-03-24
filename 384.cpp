class Solution {
public:
    vector<int> ori;
    vector<int> res;
    int len;

    Solution(vector<int>& nums) {
        ori = nums;
        res = nums;
        len = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        res = ori;
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < len; i++) {
            int idx = rand() % (len - i) + i;
            int tmp = res[idx];
            res[idx] = res[i];
            res[i] = tmp;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
