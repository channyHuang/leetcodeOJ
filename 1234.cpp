class Solution {
public:
    int balancedString(string s) {
        int len = s.length();
        int ave = len / 4;
        int count[4] = {0};//QWER
        for (int i = 0; i < len; i++) {
            int idx = change(s[i]);
            count[idx]++;
        }
        int res = 0;
        for (int i = 0; i < 4; i++) {
            count[i] = max(0, count[i] - ave);
            res += count[i];
        }
        if (res <= 1) return res;

        for (int l = res; l < len; l++) {
            int num[4] = {0};
            for (int i = 0; i < l; i++) {
                num[change(s[i])]++;
            }
            if (same(num, count)) return l;
            for (int i = l; i < len; i++) {
                num[change(s[i])]++;
                num[change(s[i - l])]--;
                if (same(num, count)) return l;
            }
        }
        
        return len;
    }

    bool same(int num[], int count[]) {
        for (int i = 0; i < 4; i++) {
            if (num[i] < count[i]) return false;
        }
        return true;
    }

    int change(char c) {
        switch(c) {
        case 'Q':
            return 0;
        case 'W':
            return 1;
        case 'E':
            return 2;
        case 'R':
            return 3;
        }
        return 0;
    }
};
