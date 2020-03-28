class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = nums.size();
        if (len <= 0) return res;
        int stPos = 0;
        int endPos = 1;
        while (endPos <= len) {
            if (endPos == len) {
                string sub = to_string(nums[stPos]);
                if (stPos != endPos - 1) {
                    sub +=  "->" + to_string(nums[endPos - 1]);
                }
                res.push_back(sub);
                break;
            }
            if (nums[endPos] == nums[endPos - 1] + 1) {
                endPos++;
                continue;
            }
            string sub = to_string(nums[stPos]);
            if (stPos != endPos - 1) {
                sub += "->" + to_string(nums[endPos - 1]);
            }
            res.push_back(sub);
            stPos = endPos;
            endPos++;
        }
        return res;
    }
};
