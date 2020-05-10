class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if (len == 1) return "";
        int pos = len / 2;
        string res = palindrome;
        int i;
        for ( i = 0; i < pos; i++) {
            if (palindrome[i] != 'a') {
                res[i] = 'a';
                break;
            }
        }
        if (i == pos) {
            res[len - 1] = 'b';
        }
        return res;
    }
};
