class Solution {
public:
    class Node {
    public:
        bool leaf;
        Node *children[26];
        int index;
        Node() {
            for (register int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            leaf = false;
            index = -1;
        }
    };
    int index = -1;

    string longestWord(vector<string>& words) {
        Node *root = new Node();
        root->leaf = true;
        for (register int i = 0; i < words.size(); i++) {
            Node *curNode = root;
            for (register int j = 0; j < words[i].length(); j++) {
                int idx = words[i][j] - 'a';
                if (curNode->children[idx] == NULL) curNode->children[idx] = new Node();
                curNode = curNode->children[idx];
            }
            curNode->leaf = true;
            curNode->index = i;
        }

        search(root, words);
        if (index == -1) return "";
        return words[index];
    }

    void search(Node *root, vector<string> words) {
        bool flag = true;
        for (register int i = 0; i < 26; i++) {
            if (root->children[i] != NULL && root->children[i]->leaf) {
                flag = false;
                search(root->children[i], words);
            }
        }
        if (flag) {
            if (index == -1) index = root->index;
            else if (words[index].length() < words[root->index].length()) index = root->index;
        }
        
    }
};
