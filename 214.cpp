class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if (len <= 1) return s;

        string_view ori = s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string_view revView = rev;
        int j;
        for (j = len; j >= 0; j--) {
            if (ori.substr(0, j) == revView.substr(len - j)) break;
        }
        return rev.substr(0, len - j) + s;
    }
};
