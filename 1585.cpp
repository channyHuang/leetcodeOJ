class Solution {
public:
    bool isTransformable(string s, string t) {
        int slen = s.length();
        vector<stack<int>> sts(10, stack<int>());

        for (int i = 0; i < slen; i++) {
            sts[s[i] - '0'].push(i);
        }

        for (int i = slen - 1; i >= 0; i--) {
            int ti = t[i] - '0';
            if (sts[ti].empty()) {             
                return false;
            }
            for (int j = ti + 1; j < 10; j++) {
                if (sts[j].empty()) continue;
                int idx = sts[j].top();
                if (idx > sts[ti].top()) return false;
            }
            sts[ti].pop();
        }
        return true;
    }
};
