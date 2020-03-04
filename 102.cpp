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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<vector<TreeNode *>> resNode;
        if (root == NULL) return res;
        {
            vector<int> subres;
            vector<TreeNode *> subNode;
            subres.push_back(root->val);
            subNode.push_back(root);
            res.push_back(subres);
            resNode.push_back(subNode);
        }
        int pos = 0;
        while (pos < res.size()) {
            vector<int> subres;
            vector<TreeNode *> subNode;
            bool flag = false;
            for (int i = 0; i < res[pos].size(); i++) {
                if (resNode[pos][i]->left) {
                    subres.push_back(resNode[pos][i]->left->val);
                    subNode.push_back(resNode[pos][i]->left);
                    flag = true;
                }
                if (resNode[pos][i]->right) {
                    subres.push_back(resNode[pos][i]->right->val);
                    subNode.push_back(resNode[pos][i]->right);
                    flag = true;
                }
            }
            if (flag) {
                res.push_back(subres);
                resNode.push_back(subNode);
            }
            pos++;
        }
        return res;
    }
};
