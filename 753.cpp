class Solution {
public:
    string crackSafe(int n, int k) {
        len = pow(k, n) + n - 1;
        res.resize(len, '0');
        if (n == 1) {
            for (int i = 0; i < k; i++) {
                res[i] = i + '0';
            }
            return res;
        }
        if (k == 1) {
            return res;
        }
        m_n = n;
        m_k = k;
        base = pow(10, n);
        sets.insert(0);
        string cur = res;
        dfs(cur, n, 0);
        return res;
    }

    void dfs(string& cur, int pos, int last) {
        if (pos >= len) {
            res = cur;
            bFound = true;
            return;
        }
        if (bFound) return;

        int next = last * 10 - base * (cur[pos - m_n] - '0');
        for (int i = 0; i < m_k; i++) {
            if (bFound) return;
            if (sets.find(next + i) == sets.end()) {
                cur[pos] = i + '0';
                sets.insert(next + i);
                dfs(cur, pos + 1, next + i);
                sets.erase(next + i);
            }
        }       
    }

private:
    unordered_set<int> sets;
    int len = 0;
    string res;
    bool bFound = false;
    int base = 0;
    int m_n, m_k;
};
