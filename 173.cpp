/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (!st.empty()) st.pop();
        if (root == NULL) return;
        pushToStack(root);
    }

    void pushToStack(TreeNode *root) {
        if (root == NULL) return;
        pushToStack(root->right);
        st.push(root);
        pushToStack(root->left);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = st.top();
        st.pop();
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    private:
    stack<TreeNode *> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
