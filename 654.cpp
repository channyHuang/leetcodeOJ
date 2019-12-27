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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root = new TreeNode(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            TreeNode *newNode = new TreeNode(nums[i]);
            if (nums[i] > root->val) {
                newNode->left = root;
                root = newNode;
            } else {
                TreeNode *curNode = root;
                while (1) {
                    if (curNode->right == NULL) {
                        curNode->right = newNode;
                        break;
                    } else if (curNode->right->val > nums[i]){
                        curNode = curNode->right;
                    } else {
                        newNode->left = curNode->right;
                        curNode->right = newNode;
                        break;
                    }
                }
            }
        }
        return root;
    }
};
