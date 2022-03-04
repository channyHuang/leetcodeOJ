// 不一定要用上所有字符。。。比如aaaaaaabb, 3的结果是bbaaa，而不是abaaabaaa
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int len = s.length();
        int i = 0;
        string res(len, ' ');
        vector<int> count(26, 0);
        for (i = 0; i < len; ++i) {
            count[s[i] - 'a']++;
        }
        int cur = 25;
        while (cur >= 0 && count[cur] <= 0) cur--;
        if (cur < 0) return res;
        int next = cur - 1;
        
        int pos = 0;
        while (cur >= 0) {
            next = cur - 1;
            while (next >= 0 && count[next] <= 0) next--;

            for (int i = 0; i < std::min(count[cur], repeatLimit); ++i) {
                res[pos++] = (cur + 'a');
            }
            if (count[cur] > repeatLimit) {
                if (next >= 0) {
                    res[pos++] = (next + 'a');
                    count[next]--;
                    if (count[next] <= 0) {
                        while (next >= 0 && count[next] <= 0) next--;
                    }
                } else break;
            }
            count[cur] -= repeatLimit;

            if (count[cur] <= 0) {
                while (cur >= 0 && count[cur] <= 0) cur--;
            }   
        }
        return res.substr(0, pos);
    }
};
