class Solution {
public:
    class Node {
    public:
        char c;
        uint32_t count;
        Node* left;
        Node* right;
        Node(char _c = ' ') : left(nullptr), right(nullptr), count(0) {}
    };

    string findDifferentBinaryString(vector<string>& nums) {
        nlen = nums.size();
        slen = nums[0].size();
        Node *root = buildTree(nums);
        string res(slen, '0');
        Node *cur = root;
        int pos = 0;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                res[pos] = '0';
                break;
            } else if (cur->right == nullptr) {
                res[pos] = '1';
                break;
            } else if (cur->left->count <= cur->right->count) {
                res[pos++] = '0';
                cur = cur->left;
            } else {
                res[pos++] = '1';
                cur = cur->right;
            }
        }
        return res;
    }

    Node *buildTree(vector<string>& nums) {
        Node *root = new Node();
        root->count = nlen;
        for (int i = 0; i < nlen; ++i) {
            Node *cur = root;
            for (int j = 0; j < slen; ++j) {
                if (nums[i][j] == '0') {
                    if (cur->left == nullptr) {
                        cur->left = new Node('0');
                    }
                    cur = cur->left;
                    cur->count++;
                } else {
                    if (cur->right == nullptr) {
                        cur->right = new Node('1');
                    }
                    cur = cur->right;
                    cur->count++;
                }
            }
        }
        return root;
    }

private:
    int nlen, slen;
};
