class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        deque<int> qu;
        qu.push_back(0);
        for (int i = 1; i < k; i++) {
            int maxn = nums[qu.front()];
            while (!qu.empty() && nums[i] >= nums[qu.back()]) qu.pop_back();
            qu.push_back(i);
        }
        res.push_back(nums[qu.front()]);
        for (int i = k; i < len; i++) {
            int maxn = nums[qu.front()];
            if (i - k == qu.front()) qu.pop_front();
            while (!qu.empty() && nums[i] >= nums[qu.back()]) qu.pop_back();
            qu.push_back(i);
            res.push_back(nums[qu.front()]);
        }
        return res;
    }
};
