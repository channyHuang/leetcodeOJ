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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return preBuild(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }

    TreeNode *preBuild(vector<int>& pre, vector<int>& post, int preSt, int preEnd, int postSt, int postEnd) {
        if (preSt > preEnd) return NULL;
        TreeNode *root = new TreeNode(pre[preSt]);
        if (preSt == preEnd) return root;
        int prePos = preSt + 1;   
        int maxPostPos = postSt;
        while (prePos <= preEnd) {
            int postPos = postSt;
            while (post[postPos] != pre[prePos]) postPos++;
            if (maxPostPos < postPos) maxPostPos = postPos;
            if (prePos - preSt == maxPostPos - postSt + 1) break;
            prePos++;
        }
        root->left = preBuild(pre, post, preSt + 1, prePos, postSt, maxPostPos);
        root->right = preBuild(pre, post, prePos + 1, preEnd, maxPostPos + 1, postEnd - 1);
        return root;
    }
};
