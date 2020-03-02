class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        if (len <= 0) return 0;
        if (len == 1) return 1;
        if (len <= k) return len;

        int count[26] = {0};
        memset(count, 0, sizeof(count));
        int left = 0; 
        int right = 0;
        int res = 1;
        count[s[0] - 'A']++;
        int maxn = 1;
        while (1) {
            if (right >= len) break;

            if (maxn + k >= right - left + 1) {
                if (res < right - left + 1) res = right - left + 1;

                right++;
                if (right >= len) break;
                count[s[right] - 'A']++;
                if (maxn < count[s[right] - 'A']) maxn = count[s[right] - 'A'];
            } else {
                left++;
                right++;
                if (right >= len) break;
                count[s[left - 1] - 'A']--;
                count[s[right] - 'A']++;
                maxn = count[0];
                for (int i = 1; i < 26; i++) {
                    if (maxn < count[i]) maxn = count[i];
                }
            }
        }
        return res;
    }
};
