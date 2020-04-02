class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
                st.push(toInt(tokens[i]));
            } else if (tokens[i].length() >= 2 && tokens[i][0] == '-' && tokens[i][1] >= '0' && tokens[i][1] <= '9') {
                st.push(toInt(tokens[i]));
            }
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                switch(tokens[i][0]) {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(b - a);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push(b / a);
                    break;
                default:
                    break;
                }
            }
        }
        return st.top();
    }

    int toInt(string s) {
        int res = 0;
        bool positive = true;
        int i = 0;
        if (s[0] == '-') {
            positive = false;
            i = 1;
        }
        for (; i < s.length(); i++) {
            res = res * 10 + s[i] - '0';
        }
        return (positive ? res : -res);
    }
};
