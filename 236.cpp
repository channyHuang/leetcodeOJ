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
    bool found[2];
    int depthpq[2];

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        found[0] = found[1] = false;
        depthpq[0] = depthpq[1] = 0;
        vector<TreeNode *> pathp, pathq;
        pathp.push_back(root);
        pathq.push_back(root);
  
        search(pathp, p, 0, 0);
        search(pathq, q, 0, 1);

        int mydepth = min(depthpq[0], depthpq[1]);
        while (pathp[mydepth] != pathq[mydepth]) {
            mydepth--;
        }
        return pathp[mydepth];
    }

    void search(vector<TreeNode *>& path, TreeNode *p, int depth, int idx) {
        if (path[depth] == p) {
            found[idx] = true;
            depthpq[idx] = depth;
            return;
        }
        
        if (path[depth]->left != NULL) {
            if (path.size() <= depth + 1) path.push_back(path[depth]->left);
            else path[depth + 1] = path[depth]->left;
            search(path, p, depth + 1, idx);
        }
        if (found[idx]) return;
        if (path[depth]->right != NULL) {
            if (path.size() <= depth + 1) path.push_back(path[depth]->right);
            else path[depth + 1] = path[depth]->right;
            search(path, p, depth + 1, idx);
        }
    }
};
