class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res = s;
        int len = s.length();
        if (len < k) return res;
        int pos = 0;
        int lastCon = 1;
        stack<int> con;
        for (int i = 1; i < len; i++) {
            if (pos < 0) {
                res[++pos] = s[i];
                lastCon = 1;
                continue;
            }
            if (pos < k - 2 || lastCon < k - 1) {
                res[++pos] = s[i];
                if (res[pos] == res[pos - 1]) lastCon++;
                else {
                    con.push(lastCon);
                    lastCon = 1;
                }
                continue;
            }
            if (res[pos] != s[i]) {
                res[++pos] = s[i];
                con.push(lastCon);
                lastCon = 1;
                continue;
            } else {
                pos -= (k - 1);
                if (con.empty()) lastCon = 0;
                else {
                    lastCon = con.top();
                    con.pop();
                }
            }
        }
        res[pos + 1] = '\0';
        return res;
    }
};
