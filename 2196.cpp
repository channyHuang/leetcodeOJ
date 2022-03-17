/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int len = descriptions.size();
        unordered_map<int, TreeNode*> maps;
        unordered_set<int> sets;
        for (int i = 0; i < len; ++i) {
            auto pitr = maps.find(descriptions[i][0]);
            TreeNode *parent = nullptr;
            if (pitr == maps.end()) {
                parent = new TreeNode(descriptions[i][0]);
                maps[descriptions[i][0]] = parent;
                sets.insert(descriptions[i][0]);
            } else {
                parent = pitr->second;
            }

            auto citr = maps.find(descriptions[i][1]);
            TreeNode *child = nullptr;
            if (citr == maps.end()) {
                child = new TreeNode(descriptions[i][1]);
                maps[descriptions[i][1]] = child;
            } else {
                child = citr->second;
                sets.erase(descriptions[i][1]);
            }

            if (descriptions[i][2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }

        auto sitr = sets.begin();
        auto itr = maps.find(*sitr);
        return itr;
    }
};
