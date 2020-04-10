class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return false;
        int minn[len];
        minn[0] = nums[0];
        for (int i = 1; i < len; i++) {
            minn[i] = min(minn[i - 1], nums[i]);
        }
        stack<int> st;
        for (int j = len - 1; j > 0; j--) {
            if (nums[j] <= minn[j]) continue;
            while (!st.empty() && st.top() <= minn[j]) st.pop();
            if (!st.empty() && st.top() < nums[j]) return true;
            st.push(nums[j]);
        }
        return false;
    }
};
