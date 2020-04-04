class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        int len = source.size();
        bool del = false;
        string pre = "";
        for (int i = 0; i < len; i++) {
            string::size_type idxLine = source[i].find("//");
            string::size_type idxBlock = source[i].find("/*");
            string::size_type endBlock;
            if (idxBlock != string::npos) endBlock = source[i].find("*/", idxBlock + 2);
            else endBlock = source[i].find("*/");
            if (del) {
                endBlock = source[i].find("*/");
                if (endBlock == string::npos) continue;
                source[i].erase(0, endBlock + 2);
                source[i] = pre + source[i];
                pre = "";
                i--;
                del = false;
                continue;
            }
            if (idxLine == string::npos && idxBlock == string::npos) {
                if (source[i].length() > 0)
                    res.push_back(source[i]);
                continue;
            }
            if (idxLine == string::npos) {
                if (endBlock == string::npos) {
                    del = true;
                    source[i].erase(idxBlock, source[i].length() - idxBlock);
                    pre = source[i];
                } else {
                    source[i].erase(idxBlock, endBlock - idxBlock + 2);
                    if (source[i].length() > 0)
                        res.push_back(source[i]);
                }
            } else if (idxBlock == string::npos) {
                source[i].erase(idxLine, source[i].length() - idxLine);
                if (source[i].length() > 0)
                    res.push_back(source[i]);
            } else {
                if (idxLine < idxBlock) {
                    source[i].erase(idxLine, source[i].length() - idxLine);
                    if (source[i].length() > 0)
                        res.push_back(source[i]);
                } else {
                    if (endBlock == string::npos) {
                        del = true;
                        source[i].erase(idxBlock, source[i].length() - idxBlock);
                        pre = source[i];
                    } else {
                        source[i].erase(idxBlock, endBlock - idxBlock + 2);
                        i--;
                    }
                }
            }
        }
        return res;
    }
};
