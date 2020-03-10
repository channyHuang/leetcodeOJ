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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        if (head->next->next == NULL) {
            TreeNode *root = new TreeNode(head->val);
            root->right = new TreeNode(head->next->val);
            return root;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *preslow = head;
        while (fast->next) {
            fast = fast->next;
            if (fast->next == NULL) break;
            preslow = slow;
            slow = slow->next;
            fast = fast->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        preslow->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};
