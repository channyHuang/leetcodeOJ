class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        res.clear();
        if (len <= 3) return res;
        int idx[4] = {0};
        
        for (int i = 0; i < 3; i++) {
            if (!valid(s, 0, i)) break;
            idx[0] = i;
            search(idx, 1, s, len);
        }
        return res;
    }

    void search(int idx[4], int curPos, string s, int len) {
        if (curPos >= 3) {
            /*debug
            {
                string str = "-";
                str += char(idx[0] + '0');
                str += char(idx[1] + '0');
                str += char(idx[2] + '0');
                res.push_back(str);
            }*/
            if (!valid(s, idx[2] + 1, len - 1)) return;
            idx[3] = len - 1;
            string str = s.substr(0, idx[0] + 1);
            for (int i = 0; i < 3; i++) {
                str += ".";
                str += s.substr(idx[i] + 1, idx[i + 1] - idx[i]);              
            }
            res.push_back(str);
            return;
        }
        for (int i = idx[curPos - 1] + 1; i < idx[curPos - 1] + 4; i++) {
            if (i >= len) break;
            if (!valid(s, idx[curPos - 1] + 1, i)) break;
            idx[curPos] = i;
            search(idx, curPos + 1, s, len);
        }
    }

    bool valid(string s, int stPos, int endPos) {
        int value = 0;
        if (endPos < stPos) return false;
        for (int i = stPos; i <= endPos; i++) {
            value = value * 10 + s[i] - '0';
            if (value > 255) return false;
            if (value == 0 && endPos > stPos) return false; 
        }
        return true;
    }
};