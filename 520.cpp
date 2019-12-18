class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstUp = false;
        bool hasLow = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                if (i == 0) firstUp = true;
                if (hasLow) return false;
            } else {
                if (i > 1 && !hasLow) return false;
                hasLow = true;
            }
        }
        return true;
    }
};
