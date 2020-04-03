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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> sets;
        for (int i = 0; i < to_delete.size(); i++) {
            sets.insert(to_delete[i]);
        }
        qu.push(root);
        while (!qu.empty()) {
            TreeNode *node = qu.front();
            qu.pop();
            set<int>::iterator itr = sets.find(node->val);
            if (itr != sets.end()) {
                if (node->left != NULL) qu.push(node->left);
                if (node->right != NULL) qu.push(node->right);
            } else {
                search(node, sets, NULL, false);
                res.push_back(node);
            }
        }
        return res;
    }

    void search(TreeNode *node, set<int> sets, TreeNode *parNode, bool left) {
        if (node == NULL ) return;
        set<int>::iterator itr = sets.find(node->val);
        if (itr != sets.end()) {
            if (node->left != NULL) qu.push(node->left);
            if (node->right != NULL) qu.push(node->right);
            if (parNode != NULL) {
                if (left) parNode->left = NULL;
                else parNode->right = NULL;
            }
            return;
        }
        search(node->left, sets, node, true);
        search(node->right, sets, node, false);
    }

private:
    vector<TreeNode *> res;
    queue<TreeNode *> qu;
};
