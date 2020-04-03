class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        int len = T.size();
        res.resize(len);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < len; i++) {
            while (!st.empty() && T[st.top()] < T[i]) {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};
