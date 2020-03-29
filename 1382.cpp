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
    TreeNode* balanceBST(TreeNode* root) {
        if (root == NULL) return root;
        if (root->left == NULL && root->right == NULL) return root;
        search(root);
        int stPos = 0, endPos = nodes.size() - 1;
        return build(stPos, endPos);
    }

    void search(TreeNode *root) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            nodes.push_back(root);
            return;
        }
        TreeNode *node = root->right;
        search(root->left);
        root->left = NULL;
        root->right = NULL;
        nodes.push_back(root);
        search(node);
    }

    TreeNode *build(int stPos, int endPos) {
        if (stPos > endPos) return NULL;
        if (stPos == endPos) return nodes[stPos];
        int midPos = (stPos + endPos) / 2;
        nodes[midPos]->left = build(stPos, midPos - 1);
        nodes[midPos]->right = build(midPos + 1, endPos);
        return nodes[midPos];
    }

private:
    vector<TreeNode *> nodes;
};
