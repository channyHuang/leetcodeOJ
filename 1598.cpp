class Solution {
public:
    int minOperations(vector<string>& logs) {
        int len = logs.size();
        stack<string> st;
        for (int i = 0; i < len; i++) {
            if (logs[i] == "./") continue;
            if (logs[i] == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(logs[i]);
            }
        }
        return st.size();
    }
};
