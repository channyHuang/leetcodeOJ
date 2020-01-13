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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *res = head->next;
        ListNode *cur = head->next;
        ListNode *tail = NULL;
        while (1) {
            head->next = cur->next;
            cur->next = head;
            if (tail == NULL) tail = head;
            else {
                tail->next = cur;
                tail = head;
            }
            if (head->next == NULL) break;
            head = head->next;
            if (head->next == NULL) break;
            cur = head->next;
        }
        return res;
    }
};