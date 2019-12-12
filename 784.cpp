class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int len = S.length();
        vector<string> res;
        char str[20] = {0};
        search(str, 0, S, res);
        return res;
    }

    void search(char str[20], int i, string S, vector<string> &res) {
        if (i >= S.length()) {
            string s = str;
            res.push_back(s);
            return;
        }
        if (S[i] >= '0' && S[i] <= '9') {
            str[i] = S[i];
            search(str, i + 1, S, res);
        } else {
            str[i] = S[i];
            search(str, i + 1, S, res);
            if (S[i] >= 'a' && S[i] <= 'z') {
                str[i] = S[i] - 'a' + 'A' ;
                search(str, i + 1, S, res);
            } else {
                str[i] = S[i] - 'A' + 'a';
                search(str, i + 1, S, res);
            }
        }
    }
};
