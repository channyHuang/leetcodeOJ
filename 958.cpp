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
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL) return true;
        TreeNode *nodes[105];
        for (int i = 0; i < 105; i++) {
            nodes[i] = NULL;
        }
        int stPos = 0;
        nodes[0] = root;
        int nextSt = 1;
        int nextPos = 1;
        bool lastLevel = false;
        while (stPos < nextPos) {
            if (nodes[stPos]->left) {
                if (lastLevel) return false;
                nodes[nextPos++] = nodes[stPos]->left;
            } else lastLevel = true;
            if (nodes[stPos]->right) {
                if (lastLevel) return false;
                nodes[nextPos++] = nodes[stPos]->right;
            } else lastLevel = true;
            stPos++;
            if (stPos == nextSt) {
                nextSt = nextPos;
            }
        }
        return true;
    }
};
