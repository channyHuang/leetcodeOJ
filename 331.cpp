class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> st;
        int len = preorder.length();
        int num = 0;
        if (preorder[len - 1] != '#') return false;
        for (int i = 0; i < len; i++) {
            if (preorder[i] == '#') {
                if (st.empty()) {
                    st.push('#');
                    i++;
                    continue;
                }
                if (st.top() == '#') {
                    st.pop();
                    if (st.empty() || st.top() != 'N') return false;
                    st.pop();
                    i--;
                } else {
                    st.push('#');
                    i++;
                }
            } else if (preorder[i] >= '0' && preorder[i] <= '9') {
                continue;
            } else {
                st.push('N');
            }
        }
        if (st.empty()) return false;
        if (st.top() != '#') return false;
        st.pop();
        return st.empty();
    }
};
