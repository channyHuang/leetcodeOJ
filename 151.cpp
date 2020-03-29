class Solution {
public:
    string reverseWords(string s) {
        if (s.length() == 0) return s;
        string::size_type pre = s.find_first_not_of(' ', 0);
        string::size_type pos = s.find_first_of(' ', pre);
        vector<string> resvec;
        string res;
        while (pre != string::npos) {
            resvec.push_back(s.substr(pre, pos - pre));
            pre = s.find_first_not_of(' ', pos);
            pos = s.find_first_of(' ', pre);
        }
        if (resvec.size() <= 0) return "";
        res = resvec[resvec.size() - 1];
        for (int i = resvec.size() - 2; i >= 0; i--) {
            res += " ";
            res += resvec[i];
        }
        return res;
    }
};
