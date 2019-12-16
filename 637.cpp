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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (root == NULL) return res;
        queue<TreeNode *> qu;
        qu.push(root);
        double sum = 0;
        int num = 1;
        int count = 0;
        while (!qu.empty()) {
            TreeNode *curNode = qu.front();
            qu.pop();
            if (curNode->left != NULL) qu.push(curNode->left);
            if (curNode->right != NULL) qu.push(curNode->right);
            sum += curNode->val;
            count++;
            if (num == count) {
                res.push_back(sum * 1.0 / num);
                sum = 0;
                num = qu.size();
                count = 0;
            }
        }
        return res;
    }
};
