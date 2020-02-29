class Solution {
public:
    class Node {
    public:
        char c;
        bool isend;
        Node *child[26];
        Node (char _c = ' ') {
            c = _c;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
                isend = false;
            }
        }
    };

    string replaceWords(vector<string>& dict, string sentence) {
        int len = dict.size();
        Node *root = new Node();
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            int slen = dict[i].length();
            for (int j = 0; j < slen; j++) {
                if (curNode->child[dict[i][j] - 'a'] == NULL) curNode->child[dict[i][j] - 'a'] = new Node(dict[i][j]);
                curNode = curNode->child[dict[i][j] - 'a'];
            }
            curNode->isend = true;
        }
        int space = 0;
        std::string res;
        while (1) {
            space = sentence.find(' ');
            if (space == std::string::npos) break;
            std::string word = sentence.substr(0, space);
            sentence = sentence.substr(space + 1);
            int tmplen = find(word, root);
            if (res.length() > 0) res += " ";
            if (tmplen == 0) {
                res += word;
                continue;
            } 
            res += word.substr(0, tmplen);
        }
        int tmplen = find(sentence, root);
        if (res.length() > 0) res += " ";
        if (tmplen == 0) {
            res += sentence;
        } else {
            res += sentence.substr(0, tmplen);
        }

        return res;
    }

    int find(std::string word, Node *root) {
        int len = word.length();
        Node *curNode = root;
        int i;
        for (i = 0; i < len; i++) {
            if (curNode->child[word[i] - 'a'] == NULL) break;
            if (curNode->isend) break;
            curNode = curNode->child[word[i] - 'a'];
        }
        if (curNode->isend) return i;
        else return 0;
    }
};
