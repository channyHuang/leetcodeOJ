class Solution {
public:
    int maxVowels(string s, int k) {
        int len = s.length();
        int maxn = 0;
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (isTarget(s[i])) maxn++;
        }
        if (maxn == k) return maxn;
        count = maxn;
        for (int i = k; i < len; i++) {
            if (isTarget(s[i])) count++;
            if (isTarget(s[i - k])) count--;
            if (count > maxn) maxn = count;
            if (maxn == k) break;
        }
        return maxn;
    }

    bool isTarget(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
};
