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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        
        vector<TreeNode *> resNode[2];
        resNode[0].push_back(root);
        int pos = 0;
        while (1) {
            int len = resNode[pos].size();
            if (len <= 0) break;
            int tmp = resNode[pos][0]->val;
            for (int i = 0; i < resNode[pos].size(); i++) {
                if (tmp < resNode[pos][i]->val) tmp = resNode[pos][i]->val;
                if (resNode[pos][i]->left != NULL) resNode[1 - pos].push_back(resNode[pos][i]->left);
                if (resNode[pos][i]->right != NULL) resNode[1 - pos].push_back(resNode[pos][i]->right);
            }
            res.push_back(tmp);
            resNode[pos].clear();
            pos = 1 - pos;
        }
        return res;
    }
};
