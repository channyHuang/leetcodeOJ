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
    class Node {
    public:
        TreeNode* node;
        int level;
        vector<TreeNode*> path;
    };

    int countPairs(TreeNode* root, int distance) {
        if (distance == 1) return 0;
        vector<TreeNode*> path;
        search(root, path, 0);
        int res = 0;
        for (int i = 0; i < nodes.size(); i++) {
            for (int j = i + 1; j < nodes.size(); j++) {
                int leveli = nodes[i].level, levelj = nodes[j].level;
                int posi = leveli, posj = levelj;
                if (leveli + levelj <= distance) {
                    res++;
                    continue;
                }
                if (leveli > levelj) {
                    posi -= (leveli - levelj);
                }
                if (leveli < levelj) {
                    posj -= (levelj - leveli);
                }
                while (nodes[i].path[posi] != nodes[j].path[posj]) {
                    posi--;
                    posj--;
                }
                if (leveli - posi + (levelj - posj) <= distance) res++;
            }
        }
        return res;
    }

    void search(TreeNode* root, vector<TreeNode*>& path, int len) {
        if (path.size() <= len) path.push_back(root);
        else path[len] = root;
        len++;
        //leaf
        if (root->left == nullptr && root->right == nullptr) {
            Node node;
            node.node = root;
            node.level = len - 1;
            for (int i = 0; i < len; i++) {
                node.path.push_back(path[i]);
            }
            nodes.push_back(node);
            return;
        }
        if (root->left != nullptr) {
            search(root->left, path, len);
        }
        if (root->right != nullptr) {
            search(root->right, path, len);
        }
    }
private:
    vector<Node> nodes;
};
