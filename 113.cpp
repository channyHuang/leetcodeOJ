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
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> subres;
        if (root == NULL) return res;
        subres.push_back(root->val);
        search(subres, root, sum, root->val, 1);
        return res;
    }

    void search(vector<int>& subres, TreeNode *root, int sum, int curSum, int nextPos) {
        if (root->left == NULL && root->right == NULL) {
            if (curSum != sum) return;
            {
                vector<int> sub;
                for (int i = 0; i < nextPos; i++) {
                    sub.push_back(subres[i]);
                }
                res.push_back(sub);
            }
            return;
        }
        
        if (root->left != NULL) {
            if (subres.size() <= nextPos) subres.push_back(root->left->val);
            else subres[nextPos] = root->left->val;
            search(subres, root->left, sum, curSum + root->left->val, nextPos + 1);
        }
        if (root->right != NULL) {
            if (subres.size() <= nextPos) subres.push_back(root->right->val);
            else subres[nextPos] = root->right->val;
            search(subres, root->right, sum, curSum + root->right->val, nextPos + 1);
        }
    }
};
