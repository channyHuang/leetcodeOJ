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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        char c[100] = {0};
        int n = root->val;
        string str;
        bool negative = false;
        if (n == 0) str = "0";
        else {
            if (n < 0) {
                str = "-";
                negative = true;
                n = -n;
            }
            int pos = 0;
            while (n) {
                c[pos++] = n % 10 + '0';
                n /= 10;
            }
            while (--pos >= 0) {
                char tmp[2] = {0};
                tmp[0] = c[pos];
                str += string(tmp);
            }
        }
        vector<string> leftres = binaryTreePaths(root->left);
        vector<string> rightres = binaryTreePaths(root->right);
        if (leftres.size() == 0 && rightres.size() == 0) {
            res.push_back(str);
            return res;
        } 
        for (int i = 0; i < leftres.size(); i++) {
            res.push_back(str + "->" + leftres[i]);
        }
        for (int i = 0; i < rightres.size(); i++) {
            res.push_back(str + "->" + rightres[i]);
        }
        return res;
    }
};
