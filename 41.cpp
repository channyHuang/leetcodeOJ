class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        set<int> sets;
        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0 || nums[i] > len) continue;
            sets.insert(nums[i]);
        }
        int res = 1;
        for (set<int>::iterator itr = sets.begin(); itr != sets.end(); itr++) {
            if (*itr == res) {
                res++;
            } else break;
        }
        return res;
    }

    int firstMissingPositive(vector<int>& nums, int stPos, int endPos) {
        if (stPos > endPos) return endPos + 2;
        int idx = fastSort(nums, stPos, stPos, endPos);
        if (nums[idx] == idx + 1) return firstMissingPositive(nums, idx + 1, endPos);
        if (idx == 0) return 1;
        return firstMissingPositive(nums, stPos, idx - 1);
    } 

    int fastSort(vector<int>& nums, int pos, int stPos, int endPos) {
        int left = stPos;
        int right = endPos;
        while (left < right) {
            while (left < pos && nums[left] <= nums[pos]) left++;
            if (nums[left] > nums[pos]) {
                int tmp = nums[left];
                nums[left] = nums[pos];
                nums[pos] = tmp;
                pos = left;
            }
            while (right > pos && nums[right] >= nums[pos]) right--; 
            if (nums[right] < nums[pos]) {
                int tmp = nums[right];
                nums[right] = nums[pos];
                nums[pos] = tmp;
                pos = right;
            }
        }
        return pos;
    }
};
