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
    int findBottomLeftValue(TreeNode* root) {
        std::vector<TreeNode *> vec;
        vec.push_back(root);
        int curlevel = 0;
        int res = curlevel;
        int nextlevel = 0;
        while (curlevel != vec.size()) {
            TreeNode *node = vec[curlevel];
            if (curlevel == nextlevel) {
                res = curlevel;
                nextlevel = vec.size();
            }
            if (node->left) vec.push_back(node->left);
            if (node->right) vec.push_back(node->right);
            curlevel++;
        }
        return vec[res]->val;
    }
};
