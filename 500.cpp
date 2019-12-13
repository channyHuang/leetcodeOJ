class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int count[26] = {2, 3, 3, 2, 1, 2, 2,
            2, 1, 2, 2, 2, 3, 3,
            1, 1, 1, 1, 2, 1, 
            1, 3, 1, 3, 1, 3};
        vector<string> res;
        int len = words.size();
        for (int i = 0; i < len; i++) {
            int sublen = words[i].length();
            if (sublen <= 1) {
                res.push_back(words[i]);
                continue;
            }
            bool flag = true;
            int curCount;
            if (words[i][0] >= 'a') curCount = count[words[i][0] - 'a'];
            else curCount = count[words[i][0] - 'A'];
            
            int nextCount;
            for (int j = 1; j < sublen; j++) {
                if (words[i][j] >= 'a') nextCount = count[words[i][j] - 'a'];
                else nextCount = count[words[i][j] - 'A'];
                if (nextCount != curCount) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(words[i]);
        }
        return res;
    }
};
