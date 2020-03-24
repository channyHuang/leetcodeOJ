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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL) return head;
        if (m == n) return head;
        
        if (m == 1) {
            ListNode *newHead = head;
            ListNode *tail = head;
            ListNode *pn = head->next;
            head->next = NULL;
            n--;
            while (n) {
                ListNode *node = pn;
                pn = pn->next;
                n--;
                node->next = newHead;
                newHead = node;
            }
            tail->next = pn;
            return newHead;
        }
        int dif = n - m;
        ListNode *prem = head;
        while (m > 2) {
            prem = prem->next;
            m--;
        }
        ListNode *pn = prem->next->next;
        ListNode *tail = prem->next;
        tail->next = NULL;
        
        while (dif) {
            ListNode *node = pn;
            pn = pn->next;
            dif--;
            node->next = prem->next;
            prem->next = node;
        }
        tail->next = pn;
        return head;
    }
};
