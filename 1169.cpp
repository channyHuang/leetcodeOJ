class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int len = transactions.size();
        vector<string> res;
        vector<bool> used;
        if (len <= 0) return res;
        used.resize(len);
        vector<vector<string>> trans;
        for (int i = 0; i < len; i++) {
            vector<string> sub;
            string::size_type pos = transactions[i].find_first_not_of(",");
            string::size_type nextPos = transactions[i].find_first_of(",", pos);
            while (1) {
                if (nextPos == string::npos) {
                    sub.push_back(transactions[i].substr(pos));
                    break;
                }
                sub.push_back(transactions[i].substr(pos, nextPos - pos));
                pos = transactions[i].find_first_not_of(",", nextPos);
                nextPos = transactions[i].find_first_of(",", pos);
            }
            sub.push_back(to_string(i));
            trans.push_back(sub);
        }
        sort(trans.begin(), trans.end(), cmp);
        int last = toInt(trans[0][1]);
        int idx;
        if (toInt(trans[0][2]) > 1000) {
            idx = toInt(trans[0][4]);
            res.push_back(transactions[idx]);
            used[idx] = true;
        }
        for (int i = 1; i < len; i++) {
            //res.push_back(transactions[toInt(trans[i][4])]);
            int next = toInt(trans[i][1]);
            if (next - last > 60) {
                if (toInt(trans[i][2]) > 1000) {
                    idx = toInt(trans[i][4]);
                    res.push_back(transactions[idx]);
                    used[idx] = true;
                }
                last = next;
                continue;
            }
            bool flag = false;
            for (int j = i - 1; j >= 0; j--) {
                last = toInt(trans[j][1]);
                if (next - last > 60 || (trans[i][0] != trans[j][0])) break;
                if (trans[i][3] != trans[j][3]) {
                    flag = true;
                    idx = toInt(trans[j][4]);
                    if (used[idx]) continue;
                    res.push_back(transactions[idx]);
                    used[idx] = true;
                }
            }
            if (flag || (toInt(trans[i][2]) > 1000)) {
                idx = toInt(trans[i][4]);
                res.push_back(transactions[idx]);
                used[idx] = true;
            }
            last = next;
        }
        return res;
    }

    static bool cmp(vector<string>& a, vector<string>& b) {
        if (a[0] == b[0]) {
            int anum = toInt(a[1]);
            int bnum = toInt(b[1]);
            return anum < bnum;
        }
        return a[0] < b[0];
    }

    static int toInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res = res * 10 + s[i] - '0';
        }
        return res;
    }
};
