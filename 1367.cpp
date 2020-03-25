/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL) return false;
        if (head == NULL) return true;
        if (startRoot(head, root)) return true;
        return (isSubPath(head, root->left) || isSubPath(head, root->right));
    }

    bool startRoot(ListNode *head, TreeNode *root) {
        if (head->val != root->val) return false;
        if (head->next == NULL) return true;
        bool res = false;
        if (root->left) res = startRoot(head->next, root->left);
        if (res) return true;
        if (root->right) res = startRoot(head->next, root->right);
        if (res) return true;
        return res;
    }
};
