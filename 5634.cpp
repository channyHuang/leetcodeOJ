class Solution {
public:
    int maximumGain(string s, int x, int y) {      
        maxn = max(x, y);
        minn = min(x, y);
        st.resize(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (x > y) {
                if (s[i] == 'a') s[i] = 'b';
                else if (s[i] == 'b') s[i] = 'a';
            }
            
            if (pos == 0) {
                st[pos++] = s[i];
            } else if (s[i] == 'a') {
                if (pos > 0 && st[pos - 1] == 'b') {
                    pos--;
                    res += maxn;
                } else {
                    st[pos++] = s[i];
                }
            } else if (s[i] != 'a' && s[i] != 'b') {
                cleanSt();
            } else {
                st[pos++] = s[i];
            }
        }
        cleanSt();
        return res;
    }

    void cleanSt() {
        stack<char> tmpst;
        for (int j = 0; j < pos; j++) {
            if (tmpst.empty() || tmpst.top() == 'b' || st[j] == 'a') {
                tmpst.push(st[j]);
                continue;
            }
            if (tmpst.top() == 'a') {
                res += minn;
                tmpst.pop();
            }
        }
        pos = 0;
    }

private:
    int res = 0;
    int pos = 0;
    int maxn, minn;
    vector<char> st;
};
