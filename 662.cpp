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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 1;
        vector<TreeNode *> vec[2];
        vec[0].push_back(root);
        int pos = 0;        
        while (1) {
            int len = vec[pos].size(), i = 0;
            if (len <= 0) break;
            while (len > 0 && vec[pos][len - 1] == NULL) len--;
            while (i < len && vec[pos][i] == NULL) i++;
            if (len <= i) {
                break;
            }
            if (res < len - i) res = len - i;
            for (; i < len; i++) {
                if (vec[pos][i] == NULL) {
                    vec[1 - pos].push_back(NULL);
                    vec[1 - pos].push_back(NULL);
                } else {
                    vec[1 - pos].push_back(vec[pos][i]->left);
                    vec[1 - pos].push_back(vec[pos][i]->right);
                }
            }
            vec[pos].clear();
            pos = 1 - pos;
        }
        return res;
    }
};
