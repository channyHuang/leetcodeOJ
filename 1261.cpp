/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    TreeNode *troot;

    FindElements(TreeNode* root) {
        troot = NULL;
        if (root == NULL) {
            return;
        }
        root->val = 0;
        recover(root);
        troot = root;
    }

    void recover(TreeNode *node) {
        if (node == NULL) return;
        if (node->left != NULL) {
            node->left->val = 2 * node->val + 1;
            recover(node->left);
        }
        if (node->right != NULL) {
            node->right->val = 2 * node->val + 2;
            recover(node->right);
        }
    }
    
    bool find(int target) {
        vector<bool> dir; //true: right, false: left
        if (target == 0) return (troot != NULL);
        while (target) {
            if (target & 1) {
                dir.push_back(false);
            }
            else {
                dir.push_back(true);
                target -= 1;
            }
            target >>= 1;
        }
        int len = dir.size();
        TreeNode *curNode = troot;
        for (int i = len - 1; i >= 0; i--) {
            if (curNode == NULL) return false;
            if (dir[i]) curNode = curNode->right;
            else curNode = curNode->left;
        }
        return curNode != NULL;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */