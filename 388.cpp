class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> st;
        int len = 0;
        int res = 0;
        string::size_type pos = input.find_first_not_of("\n");
        string::size_type next = input.find_first_of("\n", pos);
        while (pos != string::npos || next != string::npos) {
            string::size_type stpos = input.find_first_not_of("\t", pos);
            string name = input.substr(stpos, next - stpos);
            while (stpos - pos < st.size()) {
                len -= st.top().length();
                st.pop();
            }
            if (name.find(".") == string::npos) {
                name += "/";
                st.push(name);
                len += name.length();
            } else {
                if (res < len + name.length()) res = len + name.length();
            }
            pos = input.find_first_not_of("\n", next);
            next = input.find_first_of("\n", pos);
        }
        return res;
    }
};
