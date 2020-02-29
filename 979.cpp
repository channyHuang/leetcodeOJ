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
    int distributeCoins(TreeNode* root) {
        return move(root);
    }

    int move(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) return 0;
        int res = 0;
        if (root->left != NULL) {
            if (root->left->left != NULL || root->left->right != NULL) res += move(root->left);
            if (root->left->val <= 0) {
                root->val -= (1 - root->left->val);
                res += (1 - root->left->val);
                root->left->val = 1;
                
            } else if (root->left->val > 1) {
                root->val += root->left->val - 1;
                res += root->left->val - 1;
                root->left->val = 1;
            }
        }
        if (root->right != NULL) {
            if (root->right->left != NULL || root->right->right != NULL) res += move(root->right);
            if (root->right->val <= 0) {
                root->val -= (1 - root->right->val);
                res += (1 - root->right->val);
                root->right->val = 1;
                
            } else if (root->right->val > 1) {
                root->val += root->right->val - 1;
                res += root->right->val - 1;
                root->right->val = 1;
            }
        }
        
        
        return res;
    }
};
