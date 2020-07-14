class Solution {
public:
    class TreeNode {
    public:
        char c;
        TreeNode *children[26];
        int index;
        TreeNode (char _c = ' ') {
            c = _c;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            index = -1;
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();
        root = new TreeNode();
        hasWord.clear();
        hasWord.resize(words.size(), false);
        for (int i = 0; i < words.size(); i++) {
            TreeNode *node = root;
            for (int j = 0; j < words[i].length(); j++) {
                if (node->children[words[i][j] - 'a'] == nullptr) {
                    node->children[words[i][j] - 'a'] = new TreeNode(words[i][j]);
                }
                node = node->children[words[i][j] - 'a'];
            }
            node->index = i;
        }
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                search(board, i, j, root, used);
            }
        }
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            if (hasWord[i]) res.push_back(words[i]);
        }
        return res;
    }

    void search(vector<vector<char>>& mesh, int sti, int stj, TreeNode *root, vector<vector<bool>>& used) {
        if (sti < 0 || stj < 0 || sti >= rows || stj >= cols) return;
        if (used[sti][stj]) return;
        int idx = mesh[sti][stj] - 'a';
        if (root->children[idx] == nullptr) return;
        used[sti][stj] = true;
        if (root->children[idx]->index != -1) {
            hasWord[root->children[idx]->index] = true;
        }
        search(mesh, sti + 1, stj, root->children[idx], used);
        search(mesh, sti, stj + 1, root->children[idx], used);
        search(mesh, sti - 1, stj, root->children[idx], used);
        search(mesh, sti, stj - 1, root->children[idx], used);
        used[sti][stj] = false;
    }

private:
    int rows, cols;
    TreeNode *root;
    vector<bool> hasWord;
};
