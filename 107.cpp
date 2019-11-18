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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<vector<TreeNode *>> resNode;
        if (root == NULL) return res;

        vector<int> level;
        vector<TreeNode*> levelNode;
        level.push_back(root->val);
        levelNode.push_back(root);
        res.push_back(level);
        resNode.push_back(levelNode);

        int len = 0;
        while (res.size() != len) {
            len = res.size();

            vector<int> subLevel;
            vector<TreeNode *> subLevelNode;
            for (int i = 0; i < res[len-1].size(); i++) {
                if (resNode[len-1][i]->left != NULL) {
                    subLevel.push_back(levelNode[i]->left->val);
                    subLevelNode.push_back(levelNode[i]->left);
                } 
                if (resNode[len-1][i]->right != NULL) {
                    subLevel.push_back(levelNode[i]->right->val);
                    subLevelNode.push_back(levelNode[i]->right);
                }
            }
            if (subLevel.size() > 0) {
                res.push_back(subLevel);
                resNode.push_back(subLevelNode);
            }
        }
        return res;
    }
};
