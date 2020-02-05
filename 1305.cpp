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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> num1 = getElements(root1);
        vector<int> num2 = getElements(root2);
        for (int i = 0; i < num2.size(); i++) {
            num1.push_back(num2[i]);
        }
        sort(num1.begin(), num1.end());
        return num1;
    }

    vector<int> getElements(TreeNode *root) {
        vector<int> num;
        vector<TreeNode *> nodes;
        if (root == NULL) return num;
        nodes.push_back(root);
        num.push_back(root->val);
        int pos = 0;
        int len = 1;
        while (pos < len) {
            if (nodes[pos]->left) {
                nodes.push_back(nodes[pos]->left);
                num.push_back(nodes[pos]->left->val);
                len++;
            }
            if (nodes[pos]->right) {
                nodes.push_back(nodes[pos]->right);
                num.push_back(nodes[pos]->right->val);
                len++;
            }
            pos++;
        }
        return num;
    }
};