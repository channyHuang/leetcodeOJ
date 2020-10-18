class Solution {
public:
    class Node {
    public:
        char c;
        Node* children[26];
        int index;
        Node(char _c = ' ') {
            c = _c;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            index = -1;
        }
    };

    vector<vector<int>> palindromePairs(vector<string>& words) {
        int len = words.size();
        root = new Node();
        
        int nEmptyIdx = -1;
        for (int i = 0; i < len; i++) {
            Node *node = root;
            if (words[i].length() <= 0) {
                nEmptyIdx = i;
                continue;
            }
            for (int j = 0; j < words[i].length(); j++) {
                if (node->children[words[i][j] - 'a'] == nullptr) {
                    node->children[words[i][j] - 'a'] = new Node(words[i][j]);
                }
                node = node->children[words[i][j] - 'a'];
            }
            node->index = i;
        }
        //for each       
        for (int i = 0; i < len; i++) {
            if (nEmptyIdx >= 0 && nEmptyIdx != i) {
                if (valid(words[i], 0, words[i].length() - 1)) {
                    res.push_back(vector<int>({i, nEmptyIdx}));
                    res.push_back(vector<int>({nEmptyIdx, i}));
                }
            }
            if (words[i].empty()) continue;
            Node *node = root;
            int j = 0;
            //shorter word + longer word
            for (j = words[i].length() - 1; j >= 0; j--) {
                if (node->children[words[i][j] - 'a'] == nullptr) {                   
                    break;
                }
                if (node->children[words[i][j] - 'a']->index >= 0 && node->children[words[i][j] - 'a']->index != i) {
                    if (valid(words[i], 0, j - 1)) {
                        res.push_back(vector<int>({node->children[words[i][j] - 'a']->index, i}));
                    }
                }
                node = node->children[words[i][j] - 'a'];
            }
            //longer word + shorter word
            if (j < 0) {
                for (int x = 0; x < 26; x++) {
                    if (node->children[x] != nullptr) {
                        search(words, node->children[x], i, words[i].length());
                    }
                }
            }
            
        }
        return res;
    }

    void search(vector<string>& words, Node* node, int idx, int slen) {
        if (node->index >= 0 && node->index != idx) {
            if (valid(words[node->index], slen, words[node->index].length() - 1)) {
                res.push_back(vector<int>({node->index, idx}));
            }
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                search(words, node->children[i], idx, slen);
            }
        }
    }

    bool valid(string& s, int stPos, int endPos) {
        if (stPos >= endPos) return true;
        if (s[stPos] != s[endPos]) return false;
        return valid(s, stPos + 1, endPos - 1);
    }

private:
    Node* root;
    vector<vector<int>> res;
};
