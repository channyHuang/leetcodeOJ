/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "#";
        string res = to_string(root->val);
        res += "," + serialize(root->left);
        res += "," + serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode *> st; 
        stack<char> stchar;
        int len = data.length();
        int num = 0;
        TreeNode *root = NULL;
        TreeNode *right = NULL;
        for (int i = 0; i < len; i++) {
            if (data[i] == '#') {
                if (stchar.empty()) {
                    stchar.push('#');
                    st.push(right);
                    i++;
                    continue;
                }
                if (stchar.top() == '#') {
                    stchar.pop();
                    TreeNode *left = st.top();
                    st.pop();
                    stchar.pop();
                    TreeNode *root = st.top();
                    st.pop();
                    root->left = left;
                    root->right = right;
                    right = root;
                    i--;
                } else {
                    stchar.push('#');
                    st.push(right);
                    right = NULL;
                    i++;
                }
            } else if (data[i] >= '0' && data[i] <= '9') {
                num = num * 10 - '0' + data[i];
            } else {
                stchar.push('N');
                st.push(new TreeNode(num));
                num = 0;
            }
        }

        return st.top();

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
