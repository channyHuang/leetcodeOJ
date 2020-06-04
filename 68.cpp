class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = words.size();
        vector<string> res;
        int curLen = words[0].length();
        int stPos = 0;
        if (len == 1) {
            string sub = words[0];
            for (int i = curLen; i < maxWidth; i++) {
                sub += " ";
            }
            res.push_back(sub);
            return res; 
        }
        for (int i = 1; i < len; i++) {
            if (curLen + 1 + words[i].length() > maxWidth) {
                if (i == stPos + 1) {
                    string sub = words[stPos];
                    for (int j = curLen; j < maxWidth; j++) {
                        sub += " ";
                    }
                    res.push_back(sub);
                } else {
                    int addSpace = maxWidth - curLen;
                    int perSpace = addSpace / (i - stPos - 1);
                    int left = addSpace % (i - stPos - 1);

                    string sub = words[stPos];
                    string space;
                    for (int k = 0; k < perSpace; k++) {
                        space += " ";
                    }
                    for (int j = stPos + 1; j < i; j++) {
                        sub += space + " ";
                        if (left) {
                            sub += " ";
                            left--;
                        }
                        sub += words[j];
                    }
                    res.push_back(sub);
                }

                curLen = words[i].length();
                stPos = i;
                if (i == len - 1) {
                    string sub = words[stPos];
                    for (int j = words[stPos].length(); j < maxWidth; j++) {
                        sub += " ";
                    }
                    res.push_back(sub);
                }
                continue;
            } 
            curLen += words[i].length() + 1;
            if (i == len - 1) {
                string sub = words[stPos];
                for (int j = stPos + 1; j < len; j++) {
                    sub += " ";
                    sub += words[j];
                }
                for (int j = curLen; j < maxWidth; j++) {
                    sub += " ";
                }
                res.push_back(sub);
            }
        }
        return res;
    }
};
