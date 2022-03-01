class Solution {
public:
    long long countVowels(string word) {
        long long len = word.length();
        long long res = 0;
        for (int i = 0; i < len; ++i) {
            if (valid(word[i])) {
                res += ((i + 1) * (len - i));
            }
        }
        return res;
    }

    bool valid(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
};
