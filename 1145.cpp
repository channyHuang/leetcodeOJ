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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        memset(count, 0, sizeof(count));
        if (n == 1) return false;
        countNode(root);
        if (root->val == x) {
            if (root->left == NULL || root->right == NULL) return true;
            if (count[root->left->val] != count[root->right->val]) return true;
            return false;
        }
        
        TreeNode *parent = search(root, x);
        if (parent->left != NULL && parent->left->val == x) {
            int second = count[root->val] - count[x];
            if (parent->left->left != NULL && count[parent->left->left->val] > second) second = count[parent->left->left->val];
            if (parent->left->right != NULL && count[parent->left->right->val] > second) second = count[parent->left->right->val];
            return (second > count[root->val] - second ? true : false);
        } 
        if (parent->right != NULL && parent->right->val == x) {
            int second = count[root->val] - count[x];
            if (parent->right->left != NULL && count[parent->right->left->val] > second) second = count[parent->right->left->val];
            if (parent->right->right != NULL && count[parent->right->right->val] > second) second = count[parent->right->right->val];
            return (second > count[root->val] - second ? true : false);
        }
        return false;
    }

    int countNode(TreeNode *root) {
        if (root == NULL) return 0;
        int left = countNode(root->left);
        int right = countNode(root->right);
        count[root->val] = left + right + 1;
        return left + right + 1;
    }

    TreeNode * search(TreeNode *root, int target) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return NULL;
        if (root->left != NULL && root->left->val == target) return root;
        if (root->right != NULL && root->right->val == target) return root;
        TreeNode *node = search(root->left, target);
        if (node != NULL) return node;
        node = search(root->right, target);
        return node;
    }

private:
    int count[105];
};
