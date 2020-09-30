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
    enum TYPE {EMPTY, WATCHED, INSTALLED};
    
    int minCameraCover(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        res = 0;
        TYPE roottype = search(root);
        if (roottype == EMPTY) res++;  
        return res;
    }

    TYPE search(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return EMPTY;
        }
        TYPE left, right;
        if (root->left == nullptr) {
            right = search(root->right);
            if (right == EMPTY) {
                res++;
                return INSTALLED;
            } else if (right == WATCHED) {
                return EMPTY;
            } else {
                return WATCHED;
            }
        } else if (root->right == nullptr) {
            left = search(root->left);
            if (left == EMPTY) {
                res++;
                return INSTALLED;
            } else if (left == WATCHED) {
                return EMPTY;
            } else {
                return WATCHED;
            }
        } else {
            left = search(root->left);
            right = search(root->right);
            if (left == EMPTY || right == EMPTY) {
                res++;
                return INSTALLED;
            } else if (left == INSTALLED || right == INSTALLED) {
                return WATCHED;
            } else {
                return EMPTY;
            }
        }
    }

private:
    int res;
};
