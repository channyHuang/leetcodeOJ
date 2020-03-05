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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode *> res;
        if (N == 0) return res;
        if (N == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        
        return subFBT(1, N);
    }

    vector<TreeNode *> subFBT(int st, int end) {
        vector<TreeNode *> res;
        if (st > end) {
            //res.push_back(NULL);
            return res;
        }
        //if ((end - st) & 1) return res;
        if (st == end) {
            res.push_back(new TreeNode(0));
            return res;
        }
        for (int i = st + 1; i <= end; i += 2) {
            vector<TreeNode *> left = subFBT(st, i - 1);
            vector<TreeNode *> right = subFBT(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    if (root->left == NULL && root->right != NULL) continue;
                    if (root->left != NULL && root->right == NULL) continue;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

};
