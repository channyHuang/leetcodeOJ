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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        vector<vector<TreeNode *>> resNode;
        {
            vector<int> subres;
            subres.push_back(root->val);
            res.push_back(subres);
            vector<TreeNode *> subResNode;
            subResNode.push_back(root);
            resNode.push_back(subResNode);
        }
        int pos = 0;
        while (pos < res.size()) {
            vector<int> subres;
            vector<TreeNode *> subResNode;
            for (int i = 0; i < res[pos].size(); i++) {
                if (resNode[pos][i]->left != NULL) {
                    subResNode.push_back(resNode[pos][i]->left);
                    subres.push_back(resNode[pos][i]->left->val);
                } 
                if (resNode[pos][i]->right != NULL) {
                    subResNode.push_back(resNode[pos][i]->right);
                    subres.push_back(resNode[pos][i]->right->val);
                }
            }
            if (subres.size() > 0) {
                resNode.push_back(subResNode);
                if ((pos & 1) == 0) {
                    int len = subres.size();
                    for (int i = 0; i < len / 2; i++) {
                        int tmp = subres[i];
                        subres[i] = subres[len - i - 1];
                        subres[len - i - 1] = tmp;
                    }
                }
                res.push_back(subres);
            }
            pos++;
        }
        return res;
    }
};
