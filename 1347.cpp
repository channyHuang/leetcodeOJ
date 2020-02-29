class Solution {
public:
    int minSteps(string s, string t) {
        int len = s.length();
        int count[26] = {0};
        //bool hassame = false;
        for (int i = 0; i < len; i++) {
            count[s[i] - 'a']++;
            //if (!hassame && count[s[i] - 'a'] >= 2) hassame = true;
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (count[t[i] - 'a'] > 0) count[t[i] - 'a']--;
            else res++;
        }
        //if (res == 0) return (hassame ? 0 : 2);
        return res;
    }
};
