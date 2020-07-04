/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *parent = nullptr;
        TreeNode *a = nullptr, *b = nullptr;
        TreeNode *node = root;
        while (node) {
            //left is null
            if (node->left == nullptr) {
                //compare, then to right
                if (parent != nullptr && parent->val > node->val) {
                    if (a == nullptr) {
                        a = parent;
                        b = node;
                    } else {
                        b = node;
                        //found = true;
                    }
                }
                parent = node;
                node = node->right;
            } else {
                //left is not null, find parent
                TreeNode *par = node->left;
                while (par->right && par->right != node) par = par->right;
                //not visited
                if (par->right == nullptr) {
                    par->right = node;
                    node = node->left;
                } else {
                    //visited
                    if (par->val > node->val) {
                        if (a == nullptr) {
                            a = par;
                            b = node;
                        } else {
                            b = node;
                            //found = true;
                        }
                    }
                    par->right = nullptr;
                    parent = node;
                    node = node->right;
                }
            }           
        }
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};
