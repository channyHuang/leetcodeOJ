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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode *> qu;
        qu.push(root);
        int num = 1;
        int count = 0;
        
        vector<int> subres;
        while (!qu.empty()) {
            TreeNode *curNode = qu.front();
            subres.push_back(curNode->val);
            if (curNode->left != NULL) qu.push(curNode->left);
            if (curNode->right != NULL) qu.push(curNode->right);
            qu.pop();
            count++;
            if (count == num) {
                num = qu.size();
                count = 0;
                res.push_back(subres);
                subres.clear();
            }
        }
        for (int i = 0; i < res.size() / 2; i++) {
            vector<int> tmp = res[i];
            res[i] = res[res.size() - i - 1];
            res[res.size() - i - 1] = tmp;
        }
        return res;
    }
};
