class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                st.push(-1);
                continue;
            }
            if (st.top() == -1) {
                st.pop();
                int sc = 1;
                while (!st.empty() && st.top() >= 0) {
                    sc += st.top();
                    st.pop();
                }
                st.push(sc);
                continue;
            }
            int sc = st.top();
            st.pop();
            while (st.top() >= 0) {
                sc += st.top();
                st.pop();
            }
            st.pop();
            sc *= 2;
            st.push(sc);
        }
        int sc = st.top();
        st.pop();
        while (!st.empty()) {
            sc += st.top();
            st.pop();
        }
        return sc;
    }
};
