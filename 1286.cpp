class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        len = combinationLength;
        origin = characters;
        maxLen = characters.length();
        memset(used, 0, sizeof(used));
        for (int i = 0; i < len; i++) {
            index.push_back(i);
            used[i] = true;
        }
    }

    string next() {
        string str = origin.substr(0, len);
        for (int i = 0; i < len; i++) {
            str[i] = origin[index[i]];
        }
        return str;
    }
    
    bool hasNext() {
        bool flag = false;
        for (int i = 0; i < len; i++) {
            if (index[i] != maxLen - i - 1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            int pos = len - 1;
            while (1) {
                used[index[pos]] = false;      
                index[pos]++;
                while (index[pos] < maxLen && used[index[pos]]) index[pos]++;
                if (index[pos] >= maxLen) {
                    pos--;
                    continue;
                }
                break;
            }
            used[index[pos]] = true;
            pos++;
            while (pos < len) {
                for (int i = 0; i < maxLen; i++) {
                    if (used[i]) continue;
                    index[pos] = i;
                    used[i] = true;
                    break;
                }
                pos++;
            }
        }
        return flag;
    }

private:
    int len;
    string origin;
    int maxLen;
    vector<int> index;
    bool used[20];
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
