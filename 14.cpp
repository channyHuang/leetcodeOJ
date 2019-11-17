class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) return "";
        int len = 0;
        for (len = 0; len < strs[0].length(); len++) {
            bool flag = true;
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][len] == '\0') {
                    flag = false;
                    break;
                }
                if (strs[i][len] != strs[0][len]) {
                    flag = false;
                    break;
                }
            }
            if (flag == false) break;
        }
        if (len == 0) return "";
        else return strs[0].substr(0, len);
    }
};
