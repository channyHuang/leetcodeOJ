class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int len = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int endPos = nums[0];
        int stPos = 1; 
        int res = endPos;
        while (stPos <= endPos) {
            int sum = 0;
            int midPos = (stPos + endPos) / 2;
            for (int i = 0; i < len; i++) {
                sum += (nums[i] / midPos + (nums[i] % midPos == 0 ? 0 : 1));
            }
            if (sum > threshold) stPos = midPos + 1;
            else {
                if (res > midPos) res = midPos;
                endPos = midPos - 1;
            }
        }
        return res;
    }
};
