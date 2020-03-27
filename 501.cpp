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
    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return res;
        map<int, int> maps;
        maxcount = 1;
        search(maps, root);
        return res;
    }

    void search(map<int, int>& maps, TreeNode *root) {
        if (root == NULL) return;
        map<int, int>::iterator itr = maps.find(root->val);
        if (itr == maps.end()) {
            maps.insert(pair<int, int>(root->val, 1));
            if (1 == maxcount) res.push_back(root->val);
        } else {
            itr->second++;
            if (itr->second == maxcount) res.push_back(root->val);
            else if (itr->second > maxcount) {
                res.clear();
                maxcount = itr->second;
                res.push_back(root->val);
            }
        }

        search(maps, root->left);
        search(maps, root->right);
    }

private:
    int maxcount;
    vector<int> res;
};
