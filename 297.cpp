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
        string res;
        if (root == NULL) return res;
        res = to_string(root->val);
        queue<TreeNode *> qu;
        qu.push(root);
        while(!qu.empty()) {
            TreeNode *node = qu.front();
            qu.pop();
            if (node->left) {
                res += "," + to_string(node->left->val);
                qu.push(node->left);
            } else {
                res += ",null";
            }
            if (node->right) {
                res += "," + to_string(node->right->val);
                qu.push(node->right);
            } else {
                res += ",null";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return NULL;
        string::size_type pos = data.find_first_not_of(",");
        string::size_type nextPos = data.find_first_of(",", pos);
        bool left = true;
        vector<TreeNode *> vec;
        while (pos != string::npos || nextPos != string::npos) {
            string num = data.substr(pos, nextPos - pos);
            if (num == "null") vec.push_back(NULL);
            else vec.push_back(new TreeNode(toInt(num)));            
            pos = data.find_first_not_of(",", nextPos);
            nextPos = data.find_first_of(",", pos);
        }
        int i = 1;
        int posi = 0;
        TreeNode *root = vec[0];
        while (i < vec.size()) {
            vec[posi]->left = vec[i++];
            vec[posi]->right = vec[i++];
            posi++;
            while (posi < vec.size() && vec[posi] == NULL) posi++;
            if (posi >= vec.size()) break;
        }
        return root;
    }

    int toInt(string s) {
        int tmp = 0;
        int i = 0;
        bool positive = true;
        if (s[0] == '-') {
            positive = false;
            i = 1;
        }
        for (; i < s.length(); i++) {
            tmp = tmp * 10 + s[i] - '0';
        }
        return (positive ? tmp : -tmp);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
