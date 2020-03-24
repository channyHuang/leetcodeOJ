/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> maxlen;
    vector<vector<TreeNode*>> maxpath;

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> tmppath;
        if (root == NULL) return root;
        search(tmppath, root, 0);
        if (maxlen.size() == 1) return maxpath[0][maxlen[0] - 1];
        for (int i = maxlen[0] - 1; i >= 0; i--) {
            int j;
            for (j = 1; j < maxpath.size(); j++) {
                if (maxpath[j][i] != maxpath[0][i]) break;
            }
            if (j == maxpath.size()) return maxpath[0][i];
        }
        return root;
    }

    void search(vector<TreeNode*> tmppath, TreeNode *root, int pos) {
        if (root == NULL) return;
        if (tmppath.size() <= pos) tmppath.push_back(root);
        else tmppath[pos] = root;
        if (root->left == NULL && root->right == NULL) {
            if (maxlen.size() == 0 || maxlen[0] == pos + 1) {
                maxlen.push_back(pos + 1);
                vector<TreeNode*> path;
                for (int i = 0; i <= pos; i++) path.push_back(tmppath[i]);
                maxpath.push_back(path);
            } else if (maxlen[0] < pos + 1) {
                maxlen.clear();
                maxpath.clear();
                maxlen.push_back(pos + 1);
                vector<TreeNode*> path;
                for (int i = 0; i <= pos; i++) path.push_back(tmppath[i]);
                maxpath.push_back(path);
            } else return;
        } 
        if (root->left) search(tmppath, root->left, pos + 1);
        if (root->right) search(tmppath, root->right, pos + 1);
    }
};
