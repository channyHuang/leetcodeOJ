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
    TreeNode* recoverFromPreorder(string S) {
        int len = S.length();
        stack<TreeNode *> st;
        int level = 1;
        int tmp = 0;
        string::size_type pos = 0;
        for (; pos < len; pos++) {
            if (S[pos] < '0' || S[pos] > '9') break;
            tmp = tmp * 10 + S[pos] - '0';
        }
        TreeNode *root = new TreeNode(tmp);
        st.push(root);

        string::size_type nextPos = pos;
        pos = S.find_first_of("-", nextPos);
        while (pos < len) {
            nextPos = S.find_first_not_of("-", pos);
            int nextLevel = nextPos - pos;
            tmp = 0;
            for (pos = nextPos; pos < len; pos++) {
                if (S[pos] < '0' || S[pos] > '9') break;
                tmp = tmp * 10 + S[pos] - '0';
            }
            TreeNode *newNode = new TreeNode(tmp);
            if (nextLevel >= level) {
                st.top()->left = newNode;
            } else {
                while (level > nextLevel) {
                    st.pop();
                    level--;
                }
                st.top()->right = newNode;
            }
            st.push(newNode);
            level++;
        }
        return root;
    }
};
