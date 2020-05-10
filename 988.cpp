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
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        res = "";
        search(root, path);
        return res;
    }

    void search(TreeNode *root, string path) {
        char tmp[2] = {0, 0};
        tmp[0] = 'a' + root->val;
        string nextPath = string(tmp) + path;
        if (root->left == NULL && root->right == NULL) {
            if (res == "") res = nextPath;
            else if (res > nextPath) res = nextPath;
            return;
        }
        if (root->left != NULL) search(root->left, nextPath);
        if (root->right != NULL) search(root->right, nextPath);
    }

private:
    string res;
};
