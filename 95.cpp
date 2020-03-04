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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) {
            return res;
        }
        return generate(1, n);
    }

    vector<TreeNode*> generate(int st, int end) {
        vector<TreeNode*> res;
        if (st > end) {
            res.push_back(NULL);
            return res;
        };
        if (st == end) {
            res.push_back(new TreeNode(st));
            return res;
        }
        for (int i = st; i <= end; i++) {
            vector<TreeNode*> left = generate(st, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
            }
            
        }
        return res;
    }
};
