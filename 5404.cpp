class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> res;
        stack<int> st;
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            res.push_back("Push");
            if (i == target[pos]) {
                pos++;
                if (pos >= len) break;
            } else {
                res.push_back("Pop");
            }
        }
        return res;
    }
};
