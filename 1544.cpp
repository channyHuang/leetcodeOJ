class Solution {
public:
    string makeGood(string s) {
        int len = s.length();
        
        if (len <= 0) return s;
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < len; i++) {
            if (st.empty() || (abs(s[i] - st.top()) != 'a' - 'A')) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        len = st.size();
        string res = s.substr(0, len);
        int pos = len - 1;
        //cout << len << endl;
        while (!st.empty()) {
            res[pos--] = st.top();
            st.pop();
        }
        return res;
    }

    bool largeLetter(char c) {
        return (c >= 'A' && c <= 'Z');
    }
};
