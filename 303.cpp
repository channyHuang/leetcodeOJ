class NumArray {
public:
    vector<vector<int>> sums;

    NumArray(vector<int>& nums) {
        int len = nums.size();

        sums.clear();

        for (int i = 0; i < len; i++) {
            vector<int> sum;
            sum.push_back(nums[i]);
            for (int j = i + 1; j < len; j++) {
                sum.push_back(sum[j - i - 1] + nums[j]);
            }
            sums.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[i][j - i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
