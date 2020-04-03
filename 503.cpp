class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for (int i = 0; i < len; i++) {
            res.push_back(-1);
        }
        stack<int> st;
        st.push(0);
        for (int i = 1; i < len; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < len; i++) {
            if (st.empty() || st.top() == i) break;
            while (!st.empty() && nums[st.top()] < nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
        }
        return res;
    }
};
