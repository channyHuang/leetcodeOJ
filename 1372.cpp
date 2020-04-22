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
    int longestZigZag(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        int res = 1;
        queue<pair<TreeNode *, vector<int>>> qu;
        {
            vector<int> sub;
            sub.push_back(0);
            sub.push_back(0);
            qu.push(pair<TreeNode *, vector<int>>(root, sub));
        }
        while (!qu.empty()) {
            pair<TreeNode *, vector<int>> curPair = qu.front();
            if (res < curPair.second[0]) res = curPair.second[0];
            if (res < curPair.second[1]) res = curPair.second[1];
            qu.pop();
            if (curPair.first->left != NULL) {
                vector<int> sub;
                sub.push_back(curPair.second[1] + 1);
                sub.push_back(0);
                qu.push(pair<TreeNode *, vector<int>>(curPair.first->left, sub));
            }
            if (curPair.first->right != NULL) {
                vector<int> sub;
                sub.push_back(0);
                sub.push_back(curPair.second[0] + 1);
                qu.push(pair<TreeNode *, vector<int>>(curPair.first->right, sub));
            }
        }
        return res;
    }
};
