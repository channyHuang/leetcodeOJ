class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len2 < len1) return false;
        int count1[26], count2[26];
        memset(count1, 0, sizeof(count1));
        memset(count2, 0, sizeof(count2));

        for (int i = 0; i < len1; i++) {
            count1[s1[i] - 'a']++;
        }

        int left = 0;
        int right = len1 - 1;
        for (int i = left; i <= right; i++) {
            count2[s2[i] - 'a']++;
        }
        while (1) {
            int i;
            for (i = 0; i < 26; i++) {
                if (count2[i] != count1[i]) break;
            }
            if (i == 26) return true;
            count2[s2[left] - 'a']--;
            left++;
            right++;
            if (right >= len2) break;
            count2[s2[right] - 'a']++;
        }
        return false;
    }
};
