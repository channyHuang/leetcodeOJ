class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        len = (n << 1) - 1;
        res.resize(len, 0);
        vector<bool> used(n + 1, false);
        m_n = n;
        dfs(used, 0);
        return res;
    }

    void dfs(vector<bool>& used, int pos) {
        if (pos >= len) {
            found = true;
            return;
        }
        if (found) return;
        if (res[pos] != 0) {
            dfs(used, pos + 1);
            return;
        }
        for (int i = m_n; i > 0; i--) {
            if (used[i]) continue;
            if (i != 1 && (pos + i >= len || res[pos + i] != 0)) continue;
            res[pos] = i;
            if (i != 1) res[pos + i] = i;
            used[i] = true;
            dfs(used, pos + 1);
            if (found) return;
            res[pos] = 0;
            if (i != 1) res[pos + i] = 0;
            used[i] = false;
        }
    }

private:
    int len;
    int m_n;
    vector<int> res;
    bool found = false;
};
