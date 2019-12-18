class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> banword;
        for (int i = 0; i < banned.size(); i++) {
            banword.insert(banned[i]);
        }
        string res = "";
        int maxCount = 0;
        vector<int> index;
        map<string, int> maps;
        map<string, int>::iterator itr;
        for (int i = 0; i < paragraph.length(); i++) {
            if (paragraph[i] >= 'a' && paragraph[i] <= 'z') continue;
            else if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
                paragraph[i] = paragraph[i] - 'A' + 'a';
                continue;
            } 
            paragraph[i] = ' ';
            index.push_back(i);
        }
        index.push_back(paragraph.length());
        int pos = 0;
        for (int i = 0; i < index.size(); i++) {
            string str = paragraph.substr(pos, index[i] - pos);
            pos = index[i] + 1;
            if (str.length() <= 0) continue;
            if (banword.find(str) != banword.end()) continue;
            itr = maps.find(str);
            if (itr != maps.end()) {
                itr->second++;
                if (maxCount < itr->second) {
                    maxCount = itr->second;
                    res = str;
                }
            }
            else {
                maps.insert(make_pair(str, 1));
                if (maxCount == 0) {
                    maxCount = 1;
                    res = str;
                }
            }
        }
        return res;
    }
};
