class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int nlen = nums.size();
        int maxidx = 0, minidx = 0;
        for (int i = 1; i < nlen; ++i) {
            if (nums[i] > nums[maxidx]) maxidx = i;
            if (nums[i] < nums[minidx]) minidx = i;
        }
        int res = std::max(minidx + 1, maxidx + 1); //remove from left
        res = std::min(res, std::max(nlen - minidx, nlen - maxidx)); //remove from right
        res = std::min(res, (minidx + 1 + nlen - maxidx));
        res = std::min(res, (maxidx + 1 + nlen - minidx));
        return res;
    }
};
