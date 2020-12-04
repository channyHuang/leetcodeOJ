class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        len = s.length();
        used.resize(len, false);
        minn = len;
        res.clear();
        dfs(s, 0, 0, 0);

        vector<string> vres;
        //cout << res.size() << endl;
        for (unordered_set<string>::iterator itr = res.begin(); itr != res.end(); itr++) {
            //cout << *itr << endl;
            vres.push_back(*itr);
        }

        return vres;
    }

    void dfs(string& s, int pos, int left, int del) {
        if (pos >= len) {
            if (left > 0) return;
            if (del < minn) {
                minn = del;
                res.clear();
                string str;
                for (int i = 0; i < len; i++) {
                    if (used[i]) str += s.substr(i, 1);
                }
                res.insert(str);
            } else if (del == minn) {
                string str;
                for (int i = 0; i < len; i++) {
                    if (used[i]) str += s.substr(i, 1);
                }
                res.insert(str);
            }
            return;
        }
        if (del > minn) return;

        if (s[pos] != '(' && s[pos] != ')') {
            used[pos] = true;
            dfs(s, pos + 1, left, del);
        } else if (left <= 0 && s[pos] == ')') {
            used[pos] = false;
            dfs(s, pos + 1, left, del + 1);
        } else {
            used[pos] = false;
            dfs(s, pos + 1, left, del + 1);
            used[pos] = true;
            dfs(s, pos + 1, left + (s[pos] == '(' ? 1 : -1), del);
        }


    }

private:
    int len;
    vector<bool> used;
    int minn;
    unordered_set<string> res;
};