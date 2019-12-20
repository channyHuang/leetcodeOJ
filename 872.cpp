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
    int count[2][105];

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        memset(count, 0, sizeof(count));
        int idx1 = 0, idx2 = 0;
        search(root1, 0, idx1);
        search(root2, 1, idx2);
        if (idx1 != idx2) return false;
        for (int i = 0; i < idx1; i++) {
            if (count[0][i] == 0 && count[1][i] == 0) continue;
            if (count[0][i] != count[1][i]) return false;
        }
        return true;
    }

    void search(TreeNode *root, int idx, int &curIdx) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            count[idx][curIdx++] = root->val;
            return;
        }
        search(root->left, idx, curIdx);    
        search(root->right, idx, curIdx);
    }
};
