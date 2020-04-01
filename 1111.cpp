class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        if (seq.length() <= 0) return res;
        res.resize(seq.size());
        stack<char> st;
        st.push(seq[0]);
        int level = 0;
        int pos = 1;
        while (pos < seq.size()) {
            if (seq[pos] == '(') {
                st.push(seq[pos]);
                level++;
                res[pos] = level;
            } else {
                st.pop();
                res[pos] = level;
                level--;
            }
            pos++;
        }
        for (int i = 0; i < seq.size(); i++) {
            if (res[i] & 1) res[i] = 1;
            else res[i] = 0;
        }
        return res;
    }
};
