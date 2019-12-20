class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        stack<int> index;
        int minIdx = nums.size() - 1;
        int maxIdx = 0;
        index.push(0);
        for (int i = 1; i < nums.size(); i++) {
            if (index.empty() || nums[i] >= nums[index.top()]) {
                index.push(i);
                continue;
            }
            while (!index.empty()) {
                if (nums[index.top()] > nums[i]) {
                    minIdx = min(minIdx, index.top());
                    index.pop();
                }
                else break;
            }       
        }

        while (!index.empty()) index.pop();
        index.push(nums.size() - 1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (index.empty() || nums[i] <= nums[index.top()]) {
                index.push(i);
                continue;
            }
            while (!index.empty()) {
                if (nums[index.top()] < nums[i]) {
                    maxIdx = max(maxIdx, index.top());
                    index.pop();
                }
                else break;
            }
        }
        if (maxIdx + 1 <= minIdx) return 0;
        return maxIdx - minIdx + 1;
    }
};
