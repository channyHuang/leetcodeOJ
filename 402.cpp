class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        if (len <= k) return "0";
        if (len == k + 1) {
            int minn = 9;;
            for (int i = 0; i < len; i++) {
                if (num[i] - '0' < minn) minn = num[i] - '0';
            }
            return to_string(minn);
        }
        stack<char> st;
        st.push(num[0]);
        int count = 0;
        for (int i = 1; i < len; i++) {
            if (!st.empty() && st.top() > num[i] && count < k) {
                st.pop();
                count++;
                i--;
            } else {
                st.push(num[i]);
            }     
        }
        int finlen = num.length() - k;
        while (st.size() > finlen) {
            st.pop();
        }
        
        string res = num.substr(0, finlen);       
        res[finlen] = 0;
        int pos = st.size() - 1;
        while (!st.empty()) {
            res[pos--] = st.top();
            st.pop();
        }
        pos = 0;
        while (pos < finlen && res[pos] == '0') pos++;
        if (pos == finlen) return "0";
        return res.substr(pos);
    }
};
