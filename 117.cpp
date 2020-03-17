/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        if (root->right != NULL) {
            Node *node = root->next;
            while (node != NULL) {
                if (node->left != NULL) {
                    root->right->next = node->left;
                    break;
                } else if (node->right != NULL) {
                    root->right->next = node->right;
                    break;
                } else node = node->next;
            }
        }
        if (root->left != NULL) {
            if (root->right != NULL) root->left->next = root->right;
            else {
                Node *node = root->next;
                while (node != NULL) {
                    if (node->left != NULL) {
                        root->left->next = node->left;
                        break;
                    } else if (node->right != NULL) {
                        root->left->next = node->right;
                        break;
                    } else node = node->next;
                }
            }
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};
