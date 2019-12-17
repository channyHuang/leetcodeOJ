class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        vector<string> res;
        if (len <= 0) return res;
        int count[26] = {0};
        for (int i = 0; i < A[0].length(); i++) {
            count[A[0][i] - 'a']++;
        }
        for (int i = 1; i < len; i++) {
            int comp[26] = {0};
            for (int j = 0; j < A[i].length(); j++) {
                comp[A[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; j++)
                count[j] = min(count[j], comp[j]);
        }
        for (int i = 0; i < 26; i++) {
            char tmp[2] = {0};
            tmp[0] = i + 'a';
            while (count[i]--) res.push_back(string(tmp));
        }
        return res;
    }
};
