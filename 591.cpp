class Solution {
public:
    bool isValid(string code) {
        int len = code.length();
        if (len < 7) return false;
        if (code[0] != '<' || code[len - 1] != '>') return false;
        stack<string> st;
        int nlen;
        bool bEnd;
        for (int i = 0; i < len; i++) {
            if (code[i] == '<') {
                //end of tag
                if (code[i + 1] == '/') {
                    bEnd = validTagName(code, i + 2, nlen);
                    if (!bEnd || st.empty() || st.top() != code.substr(i + 2, nlen)) return false;
                    st.pop();
                    i += 2 + nlen;
                } else if (code[i + 1] == '!') { //cdata
                    if (st.empty()) return false;
                    bEnd = validCdata(code, i + 2, nlen);
                    if (!bEnd) return false;
                    i = nlen;
                    continue;
                } else { //start of tag
                    bEnd = validTagName(code, i + 1, nlen);
                    if (!bEnd) return false;
                    if (st.empty() && i != 0) return false;
                    st.push(code.substr(i + 1, nlen));
                    i += nlen;
                } 
            } else {
                if (st.empty()) return false;
            }
        }
        return st.empty();
    }
    //from < or </
    bool validTagName(string str, int stPos, int& nlen) {
        //empty
        if (stPos >= str.length() || str[stPos] == '>') return false;
        for (int i = 0; i < 10; i++) {
            if (stPos + i >= str.length()) return false;
            if (str[stPos + i] == '>') {
                nlen = i;
                return true;
            }
            if (str[stPos + i] > 'Z' || str[stPos + i] < 'A') return false;
        }
        return false;
    }
    //from <!
    bool validCdata(string str, int stPos, int& endPos) {
        if (stPos + 9 >= str.length()) return false;
        if (str.substr(stPos, 7) != "[CDATA[") return false;
        int i = stPos + 7; 
        while (i < str.length()) {
            if (str.substr(i, 3) == "]]>") {
                endPos = i + 2;
                return true;
            }
            i++;
        }

        return false;
    }
};
