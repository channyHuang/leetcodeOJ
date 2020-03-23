/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *res = head;
        ListNode *node = head->next;
        res->next = NULL;
        while (node) {
            if (node->val <= res->val) {
                ListNode *tmp = node;
                node = node->next;
                tmp->next = res;
                res = tmp;
            } else {
                ListNode *pre = res;
                while (pre->next && pre->next->val < node->val) pre = pre->next;
                ListNode *tmp = node;
                node = node->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
        }
        return res;
    }
};
