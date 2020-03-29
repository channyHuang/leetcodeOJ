/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        count = 0;
        if (root == NULL) return;
        nodes.push_back(root);
        int pos = 0;
        count = 1;
        while (pos < count) {
            TreeNode *node = nodes[pos];
            if (node->left) {
                nodes.push_back(node->left);
                count++;
            }
            if (node->right) {
                nodes.push_back(node->right);
                count++;
            }
            pos++;
        }
    }
    
    int insert(int v) {
        TreeNode *node = new TreeNode(v);
        nodes.push_back(node);
        if (count > 0) {
            int idx = (count - 1) / 2;
            if (idx * 2 + 1 == count) nodes[idx]->left = node;
            else nodes[idx]->right = node;
            count++;
            return nodes[idx]->val;
        }       
        count++;
        return v;
    }
    
    TreeNode* get_root() {
        return nodes[0];
    }

private:
    vector<TreeNode *> nodes;
    int count;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
