class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string res = s;
        int pos = 0;
        int i = 0;
        while (s[i] == '(' || s[i] == ')') i++;
        for (; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') res[pos++] = s[i];
            else if (s[i] == '(') {
                st.push('(');
                res[pos++] = s[i];
            } else {
                if (st.empty()) continue;
                st.pop();
                if (res[pos - 1] == '(') continue;
                res[pos++] = s[i];
            }
        }
        res[pos] = 0;
        while (!st.empty()) {
            string::size_type pos = res.find_last_of("(");
            res.replace(pos, res.length() - pos, res.substr(pos + 1));
            st.pop();
        }
        return res;
    }
};
