class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        lena = A.size(), lenb = B.size();
        vector<int> countb(26, 0);
        for (int i = 0; i < lenb; i++) {
            vector<int> cnt(26, 0);
            for (int j = 0; j < B[i].length(); j++) {
                cnt[B[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                countb[j] = max(countb[j], cnt[j]);
            }
        }
        vector<string> res;
        for (int i = 0; i < lena; i++) {
            vector<int> cnt(26, 0);
            for (int j = 0; j < A[i].length(); j++) {
                cnt[A[i][j] - 'a']++;
            }
            bool valid = true;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] < countb[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) res.push_back(A[i]);
        }
        return res;
    }
private:
    int lena, lenb;
};
