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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        res.push_back(root->val);
        {
            vector<TreeNode *> resNode[2];
            resNode[0].push_back(root);
            int pos = 0;
            while (1) {
                resNode[1 - pos].clear();
                for (int i = 0; i < resNode[pos].size(); i++) {
                    if (resNode[pos][i]->left) resNode[1 - pos].push_back(resNode[pos][i]->left);
                    if (resNode[pos][i]->right) resNode[1 - pos].push_back(resNode[pos][i]->right);
                }
                if (resNode[1 - pos].size() == 0) break;
                res.push_back(resNode[1 - pos][resNode[1 - pos].size() - 1]->val);
                pos = 1 - pos;
            }
        }
        return res;
    }
};
