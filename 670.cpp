class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int maxn = str[0] - '0';
        int i;
        for (i = 1; i < str.length(); i++) {
            if (str[i] <= str[i - 1]) continue;
            break;
        }
        if (i >= str.length()) return num;
        int chgIdx = i - 1;
        int idx = i;
        for (; i < str.length(); i++) {
            if (str[i] >= str[idx]) idx = i;
        }
        while (chgIdx > 0 && str[chgIdx - 1] < str[idx]) chgIdx--;
        char tmp = str[idx];
        str[idx] = str[chgIdx];
        str[chgIdx] = tmp;
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            res = res * 10 + str[i] - '0';
        }
        return res;
    }
};
