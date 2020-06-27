class Solution {
public:
    string lastSubstring(string s) {
        int len = s.length();
        string_view str(s);
        string_view res = str;
        for (string_view::iterator itr = str.begin() + 1; itr != str.end(); itr++) {
            if (*itr < *res.begin() || *itr <= *(itr - 1)) continue;
            if (lexicographical_compare(res.begin(), res.end(), itr, str.end())) res = str.substr(itr - str.begin());
        }
        return (string)res;
    }
};