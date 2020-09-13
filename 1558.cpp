class Solution {
public:
    int minOperations(vector<int>& nums) {
        len = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        int pos = 0;
        while (pos < len && nums[pos] == 0) pos++;
        if (pos >= len) return res;
        res += op1(nums, pos);
        while (nums[len - 1] != 0) {
            res++;
            res += op2(nums, pos);
        }
        return res;
    }
    
    int op1(vector<int>& nums, int& stPos) {
        int res = 0;
        for (int i = stPos; i < len; i++) {
            if (nums[i] & 1) {
                nums[i]--;
                res++;
            }
            if (nums[i] == 0) stPos++;
        }
        return res;
    }

    int op2(vector<int>& nums, int stPos) {
        int res = 0;
        for (int i = stPos; i < len; i++) {
            nums[i] >>= 1;
            if (nums[i] & 1) {
                res++;
                nums[i]--;
                if (nums[i] == 0) stPos++;
            }
        }
        return res;
    }

private:
    int len;
};
