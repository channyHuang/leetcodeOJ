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
    vector<vector<string>> printTree(TreeNode* root) {   
        if (root == NULL) return res;
        height = 0;
        int width = searchWidth(root, 1);
        for (int i = 0; i < height; i++) {
            vector<string> sub;
            sub.resize(width);
            res.push_back(sub);
        }
        pushData(root, 0, width - 1, 0);
        return res;
    }

    int searchWidth(TreeNode *root, int h) {
        if (root == NULL) return 0;
        height = max(height, h);
        int left = searchWidth(root->left, h + 1);
        int right = searchWidth(root->right, h + 1);
        return max(left, right) * 2 + 1;
    }

    void pushData(TreeNode *root, int stPos, int endPos, int h) {
        if (root == NULL) return;
        int midPos = (stPos + endPos) / 2;
        res[h][midPos] = to_string(root->val);
        pushData(root->left, stPos, midPos - 1, h + 1);
        pushData(root->right, midPos + 1, endPos, h + 1);
    }

private:
    int height;
    vector<vector<string>> res;
};
