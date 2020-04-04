class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> count;
        int pos = 0;
        count.push_back(1);
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[pos]) {
                count[pos]++;
            } else {
                count.push_back(1);
                pos++;
                nums[pos] = nums[i];
            }
        }
        len = pos + 1;
        for (int i = 0; i < len; i++) {
            if (count[i] == 0) continue;
            if (i + k > len) return false;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] - nums[i] != j - i) return false;
                count[j] -= count[i];
                if (count[j] < 0) return false;
            }
        }
        return true;
    }
};
