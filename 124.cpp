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
    int maxPathSum(TreeNode* root) {
        finres = root->val;
        int left = maxSum(root->left);
        int right = maxSum(root->right);
        int rootres = root->val;
        if (left > 0) {
            rootres = rootres + left;
        }
        if (right > 0) {
            rootres = rootres + right;
        }
        //std::cout << finres << std::endl;
        return max(finres, rootres);
    }

    int maxSum(TreeNode *root) {
        if (root == nullptr) return 0;
        int res = root->val;
        int left = maxSum(root->left);
        int right = maxSum(root->right);

        //std::cout << root->val << ":" << left << " " << right << std::endl;
        if (left > right) {
            if (left > 0) res = res + left;
        } else {
            if (right > 0) res = res + right;
        }
        //std::cout << root->val << ":" << res << std::endl;

        int sub = root->val;
        if (left > 0) sub += left;
        if (right > 0) sub += right;
        if (sub > finres) finres = sub;
        return res;
    }

private:
    int finres;
};
