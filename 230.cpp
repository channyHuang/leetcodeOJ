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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        find(root, vec);
        return vec[k - 1];
    }

    void find(TreeNode* root, vector<int>& vec) {
        if (root == NULL) return;
        find(root->left, vec);
        vec.push_back(root->val);
        find(root->right, vec);
    }    
};
