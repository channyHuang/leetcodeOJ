class Solution {
public:
    int strongPasswordChecker(string s) {
        bool contain[3] = {false, false, false};
        int len = s.length();
        vector<int> modleft(3, 0);
        int i = 0;
        int res = 0;
        while (i < len) {
            if (s[i] >= 'a' && s[i] <= 'z') contain[0] = true;
            else if (s[i] >= 'A' && s[i] <= 'Z') contain[1] = true;
            else if (s[i] >= '0' && s[i] <= '9') contain[2] = true;
        
            int nexti = i;
            while (s[nexti] == s[i]) nexti++;
            int cnt = nexti - i;
            if (cnt >= 3) {
                modleft[cnt % 3]++;
                res += cnt / 3;
            }
            i = nexti;
        }
        int nInsert = 0;
        for (int i = 0; i < 3; i++) {
            if (!contain[i]) nInsert++;
        }
    
        if (len < 6) {
            return max(nInsert, 6 - len);
        } else if (len <= 20) {
            return max(res, nInsert);
        } else {
            int needdel = len - 20;
            if (needdel < modleft[0]) {
                return max(res - needdel, nInsert) + needdel;
            }
            needdel -= modleft[0];
            res -= modleft[0];
            if (needdel < modleft[1] * 2) {
                return max(res - needdel / 2, nInsert) + len - 20;
            }
            needdel -= (modleft[1] * 2);
            res -= modleft[1];
            return max(res - needdel / 3, nInsert) + len - 20;       
        }
        return 0;
    }
};
