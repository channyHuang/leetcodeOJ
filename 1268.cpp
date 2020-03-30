class Solution {
public:
    class Node {
    public:
        vector<string> strs;
        Node *child[26];
        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int len = products.size();
        vector<vector<string>> res;
        if (len <= 0) {
            for (int i = 0; i < searchWord.length(); i++) {
                vector<string> subres;
                res.push_back(subres);
            }
            return res;
        }
        Node *root = new Node();
        sort(products.begin(), products.end());
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            for (int j = 0; j < products[i].length(); j++) {
                if (curNode->child[products[i][j] - 'a'] == NULL) {
                    curNode->child[products[i][j] - 'a'] = new Node();
                }
                curNode = curNode->child[products[i][j] - 'a'];
                if (curNode->strs.size() < 3) {
                    curNode->strs.push_back(products[i]);
                }
            }
        }
        Node *curNode = root;
        for (int i = 0; i < searchWord.length(); i++) {
            if (curNode->child[searchWord[i] - 'a'] == NULL) {
                for (int j = i; j < searchWord.length(); j++) {
                    vector<string> subres;
                    res.push_back(subres);
                }
                break;
            }
            curNode = curNode->child[searchWord[i] - 'a'];
            res.push_back(curNode->strs);
        }
        return res;
    }
};
