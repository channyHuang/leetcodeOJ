class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector<int> res;
        int count[2][26][1001] = {0};
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].length(); j++) {
                count[j % 2][A[i][j] - 'a'][i]++;
            }
            bool add = true;
            for (int j = 0; j < res.size(); j++) {
                int k;
                for (k = 0; k < 26; k++) {
                    if (count[0][k][i] != count[0][k][res[j]]) {
                        break;
                    }
                    if (count[1][k][i] != count[1][k][res[j]]) {
                        break;
                    }
                }
                if (k == 26) {
                    add = false;
                    break;
                }
            }
            if (add) res.push_back(i);
        }
        return res.size();
    }
};
