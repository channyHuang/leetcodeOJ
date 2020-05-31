/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        res = 0;
        search(root, count);
        return res;
    }

    void search(TreeNode* root, vector<int>& count) {
        count[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int odd = 0;
            for (int i = 0; i < 10; i++) {
                if ((count[i] & 1) == 0) continue;
                odd++;
                if (odd > 1) break;
            }
            if (odd <= 1) res++;
            count[root->val]--;
            return;
        }
        if (root->left) search(root->left, count);
        if (root->right) search(root->right, count);
        count[root->val]--;
    }

private:
    int res;
};
