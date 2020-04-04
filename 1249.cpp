class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        stack<int> index;
        string res = s;
        int pos = 0;
        int i = 0;
        while (s[i] == ')') i++;
        for (; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') res[pos++] = s[i];
            else if (s[i] == '(') {
                st.push('(');
                index.push(pos);
                res[pos++] = s[i];
            } else {
                if (st.empty()) continue;
                st.pop();
                index.pop();
                res[pos++] = s[i];
            }
        }
        res[pos] = 0;
        while (!st.empty()) {
            int pos = index.top();
            res.replace(pos, res.length() - pos, res.substr(pos + 1));
            st.pop();
            index.pop();
        }
        return res;
    }
};
