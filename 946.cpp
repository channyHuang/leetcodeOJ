class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        if (len <= 2) return true;
        bool used[1005] = {0};
        stack<int> st;
        st.push(pushed[0]);
        used[pushed[0]] = true;
        int pospush = 1;
        int pospop = 0;
        while (pospush != len) {
            while (!st.empty() && popped[pospop] == st.top()) {
                st.pop();
                pospop++;
                continue;
            }
            if (pushed[pospush] == popped[pospop]) {
                pospush++;
                pospop++;
                continue;
            }
            if (used[popped[pospop]]) return false;
            st.push(pushed[pospush]);
            used[pushed[pospush]] = true;
            pospush++;
        }
        while (!st.empty()) {
            if (st.top() == popped[pospop]) {
                st.pop();
                pospop++;
            } else return false;
        }
        return true;
    }
};
