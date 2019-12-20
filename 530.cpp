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
    int getMinimumDifference(TreeNode* root) {
          if (root == NULL) return -1;
          if (root->left == NULL && root->right == NULL) return -1;
          int res = root->val;
          if (root->right != NULL) {
              TreeNode *node = root->right;
              while (node->left != NULL) node = node->left;
              res = node->val - root->val;
              if (root->right->left != NULL || root->right->right != NULL) {
                int tmp = getMinimumDifference(root->right);
                res = min(res, tmp);
              }
          }
          if (root->left != NULL) {
              TreeNode *node = root->left;
              while (node->right != NULL) node = node->right;
              res = min(res, root->val - node->val);
              if (root->left->left != NULL || root->left->right != NULL) {
                int tmp = getMinimumDifference(root->left);
                res = min(res, tmp);
              }
          }
          return res;
    }
}; 
