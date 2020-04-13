class Solution {
public:
    class Node {
    public:
        string str;
        int cnt;
        long long totalLen;
        Node(string _str = "", int _cnt = 0) {
            str = _str;
            cnt = _cnt;
            totalLen = 0;
        }
    };

    string decodeAtIndex(string S, int K) {
        int len = S.length();
        int stPos = 0;
        int pos = 0;
        stack<Node> st;
        while (stPos < len) {
            while (pos < len && S[pos] >= 'a' && S[pos] <= 'z') pos++;
            if (pos >= len) {
                Node node(S.substr(stPos), 1);
                if (st.empty()) node.totalLen = (len - stPos);
                else node.totalLen = (len - stPos + st.top().totalLen);
                st.push(node);
                break;
            }
            Node node(S.substr(stPos, pos - stPos), S[pos] - '0');
            if (st.empty()) node.totalLen = (pos - stPos) * (S[pos] - '0');
            else node.totalLen = (pos - stPos + st.top().totalLen) * (S[pos] - '0');
            st.push(node);
            stPos = pos + 1;
            pos = pos + 1;
            if (node.totalLen >= K) break;
        }
        int count = K - 1;
        Node node = st.top();
        st.pop();
        while (1) {
            if (st.empty()) {
                count %= node.str.length();
                return node.str.substr(count, 1);
            }
            count %= (st.top().totalLen + node.str.length());
            if (count >= st.top().totalLen) return node.str.substr(count - st.top().totalLen, 1);
            node = st.top();
            st.pop();
        }
        return "";
    }
};
