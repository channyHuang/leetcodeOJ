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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (root == NULL) return res;
        search(root);
        return res;
    }

    string search(TreeNode *root) {
        if (root == NULL) return "#";
        string str = to_string(root->val);
        str += ",";
        str += search(root->left);
        str += ",";
        str += search(root->right);
        itr = maps.find(str);
        if (itr == maps.end()) {
            maps.insert(pair<string, int>(str, 1));
        } else {
            if (itr->second == 1) {
                res.push_back(root);
            }
            itr->second++;
        }
        return str;
    }

private:
    vector<TreeNode*> res;
    unordered_map<string, int> maps;
    unordered_map<string, int>::iterator itr;
};
