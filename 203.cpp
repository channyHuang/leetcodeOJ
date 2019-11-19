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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        ListNode *res = head;
        ListNode *tmp;
        while (res != NULL && res->val == val) {
            tmp = res;
            res = res->next;
            delete tmp;
        }

        if (res == NULL) return NULL;

        ListNode *node = res;
        while (node != NULL && node->next != NULL) {
            if (node->next->val == val) {
                tmp = node->next;
                node->next = tmp->next;
                delete tmp;
            } else {
                node = node->next;
            }
        }

        return res;
    }
};
