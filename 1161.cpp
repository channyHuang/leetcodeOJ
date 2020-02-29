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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode *> vec;
        if (root == NULL) return 0;
        vec.push_back(root);
        int curlevelidx = 0;
        int nextlevelidx = 1;
        int res = 1;
        int ressum = root->val;
        int curlevel = 1;

        int cursum = 0;
        while (curlevelidx < vec.size()) {
            TreeNode *node = vec[curlevelidx];
            if (curlevelidx == nextlevelidx) {
                if (cursum > ressum) {
                    ressum = cursum;
                    res = curlevel;
                }
                cursum = 0;
                nextlevelidx = vec.size();
                curlevel++;
            }
            if (node->left) {
                vec.push_back(node->left);
            }
            if (node->right) {
                vec.push_back(node->right);
            }
            cursum += node->val;
            curlevelidx++;
        }
        if (cursum > ressum) {
            ressum = cursum;
            res = curlevel;
        }
        return res;
    }
};
