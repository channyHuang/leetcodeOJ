class Solution {
public:
    string simplifyPath(string path) {
        vector<string> files = split(path, "/");
        int len = files.size();
        vector<string> st;
        st.resize(len + 1);
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (files[i] != "." && files[i] != "..") st[pos++] = files[i];
            else if (files[i] == ".") continue;
            else {
                if (pos == 0) continue;
                pos--;
            }
        }
        string res;
        for (int i = 0; i < pos; i++) {
            res += "/";
            res += st[i];
        }
        return res;
    }

    vector<string> split(string path, string delimiters = " ") {
        vector<string> res;
        string::size_type prePos = path.find_first_not_of(delimiters, 0);
        string::size_type nextPos = path.find_first_of(delimiters, prePos);
        while (prePos != string::npos || nextPos != string::npos) {
            res.push_back(path.substr(prePos, nextPos - prePos));
            prePos = path.find_first_not_of(delimiters, nextPos);
            nextPos = path.find_first_of(delimiters, prePos);
        }
        return res;
    }
};
