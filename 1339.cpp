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
    int maxProduct(TreeNode* root) {
        long long res = 0;
        long long mulSum = calcSum(root);
        for (set<long long>::iterator itr = sets.begin(); itr != sets.end(); itr++) {
            if (mulSum == *itr) continue;
            res = max(res, (mulSum - *itr) * (*itr));
        }
        return res % maxn;
    }

    long long calcSum(TreeNode *root) {
        if (root == NULL) return 0;
        long long left = 0;
        long long right = 0;
        if (root->left != NULL) {
            left = calcSum(root->left);
        }
        if (root->right != NULL) {
            right = calcSum(root->right);
        }
        sets.insert(root->val + right + left);
        return root->val + right + left;
    }

private:
    int maxn = 1000000007;
    set<long long> sets;
};
