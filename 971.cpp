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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int len = voyage.size();
        if (root == NULL) {
            if (len == 0) return res;
            res.push_back(-1);
            return res;
        }
        countNode(root);
        if (len != count[root->val] || voyage[0] != root->val) {
            res.push_back(-1);
            return res;
        }
        flag = true;
        search(root, voyage, 0, len - 1);
        if (!flag) {
            res.clear();
            res.push_back(-1);
        }
        return res;
    }

    int countNode(TreeNode *root) {
        if (root == NULL) return 0;
        int left = countNode(root->left);
        int right = countNode(root->right);
        count[root->val] = left + right + 1;
        return count[root->val];
    }

    void search(TreeNode *root, vector<int>& voyage, int stPos, int endPos) {
        if (stPos == endPos && root->val == voyage[stPos]) return;
        if (!flag) return;
        if (count[root->val] != endPos - stPos + 1 || root->val != voyage[stPos]) {
            flag = false;
            return;
        }
        if (root->left == NULL) {
            search(root->right, voyage, stPos + 1, endPos);
            return;
        }
        if (root->right == NULL) {
            search(root->left, voyage, stPos + 1, endPos);
            return;
        }
        if (voyage[stPos + 1] == root->left->val) {
            search(root->left, voyage, stPos + 1, stPos + count[root->left->val]);
            search(root->right, voyage, stPos + count[root->left->val] + 1, endPos);
        } else {
            res.push_back(root->val);
            search(root->right, voyage, stPos + 1, stPos + count[root->right->val]);
            search(root->left, voyage, stPos + count[root->right->val] + 1, endPos);
        }
    }

private:
    int count[105];
    vector<int> res;
    bool flag;
};
