class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int res = 0;
        vector<string> vec(len, "");
        int pos = 0;
        int stPos = 0;
        while (stPos < len && s[stPos] == ')') stPos++;
        if (stPos >= len) return 0;
        for (int i = stPos; i < len; i++) {
            if (s[i] == '(') {
                vec[pos++] = s.substr(i, 1);
            } else {
                if (vec[pos - 1] == "(") {
                    vec[pos - 1] = to_string(2);
                    while (pos - 2 >= 0 && vec[pos - 2] != "(" && vec[pos - 2] != ")") {
                        vec[pos - 2] = add(vec[pos - 2], vec[pos - 1]);
                        pos--;
                    }
                } else if (pos >= 2 && vec[pos - 2] == "(") {
                    vec[pos - 2] = add(vec[pos - 1], to_string(2));
                    pos--;
                    while (pos - 2 >= 0 && vec[pos - 2] != "(" && vec[pos - 2] != ")") {
                        vec[pos - 2] = add(vec[pos - 2], vec[pos - 1]);
                        pos--;
                    }
                } else {
                    vec[pos++] = s.substr(i, 1);
                }
            }
            /*for (int i = 0; i < pos; i++) {
                std::cout << vec[i] << " ";
            }
            std::cout << std::endl;*/
        }
        for (int i = 0; i < pos; i++) {
            if (vec[i] == "(") continue;
            res = max(res, toInt(vec[i]));
            //std::cout << vec[i] << " ";
        }
        return res;
    }

    string add(string a, string b) {
        int na = toInt(a);
        int nb = toInt(b);
        return to_string(na + nb);
    }

    int toInt(string a) {
        int na = 0;
        for (int i = 0; i < a.length(); i++) {
            na = na * 10 + a[i] - '0';
        }
        return na;
    }
};
