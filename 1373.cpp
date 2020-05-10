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
    int maxSumBST(TreeNode* root) {
        res = -2000000000;
        bool flag = true;
        int sum = 0;
        calcSum(root, flag, sum);
        return res;
    }

    void calcSum(TreeNode* root, bool& flag, int& sum) {
        if (root == NULL) {
            flag = true;
            sum = 0;
            res = max(res, sum);
            return;
        }
        bool flagleft = true, flagright = true;
        int sumleft = 0, sumright = 0;
        calcSum(root->left, flagleft, sumleft);
        calcSum(root->right, flagright, sumright);
        if (!flagleft || !flagright) flag = false;
        else if (root->right != NULL && root->right->val <= root->val) {
            flag = false;
        }
        else if (root->left != NULL && root->left->val >= root->val) {
            flag = false;
        }
        if (flag) {
            sum = sumleft + sumright + root->val;
            res = max(res, sum);
        }
    }

private:
    int res;
};
