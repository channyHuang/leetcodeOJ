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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        if (head->next->next == NULL) {
            if (head->val > head->next->val) {
                int tmp = head->val;
                head->val = head->next->val;
                head->next->val = tmp;
            }
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL) {
            fast = fast->next;
            if (fast == NULL) break;
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *sub = slow->next;
        slow->next = NULL;
        head = sortList(head);
        sub = sortList(sub);
        ListNode *res = head;
        while (sub) {
            if (sub->val <= res->val) {
                ListNode *node = sub;
                sub = sub->next;
                node->next = res;
                res = node;
            } else break;           
        }
        ListNode *cur = res;
        while (sub) {
            if (cur->next == NULL) {
                cur->next = sub;
                return res;
            }
            if (cur->next->val > sub->val) {
                ListNode *node = sub;
                sub = sub->next;
                node->next = cur->next;
                cur->next = node;
            } else cur = cur->next;
        }
        return res;
    }
};
