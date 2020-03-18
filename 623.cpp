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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *node = new TreeNode(v);
            node->left = root;
            return node;
        }
        vector<TreeNode *> vec[2];
        vec[0].push_back(root);
        int pos = 0;
        int level = 1;
        while (level != d - 1) {
            for (int i = 0; i < vec[pos].size(); i++) {
                if (vec[pos][i]->left) vec[1 - pos].push_back(vec[pos][i]->left);
                if (vec[pos][i]->right) vec[1 - pos].push_back(vec[pos][i]->right);
            }
            vec[pos].clear();
            level++;
            pos = 1 - pos;
        }
        for (int i = 0; i < vec[pos].size(); i++) {
            TreeNode *left = new TreeNode(v);
            TreeNode *right = new TreeNode(v);
            left->left = vec[pos][i]->left;
            right->right = vec[pos][i]->right;
            vec[pos][i]->left = left;
            vec[pos][i]->right = right;
        }
        return root;
    }
};
