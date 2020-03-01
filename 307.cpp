class NumArray {
public:
    vector<int> num;
    vector<int> sum;

    NumArray(vector<int>& nums) {
        num = nums;
        if (nums.size() == 0) return;
        sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sum.push_back(sum[i - 1] + nums[i]);
        }
    }
    
    void update(int i, int val) {
        int dif = val - num[i];
        num[i] = val;
        for (int x = i; x < num.size(); x++) {
            sum[x] += dif;
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return sum[j];
        return sum[j] - sum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
