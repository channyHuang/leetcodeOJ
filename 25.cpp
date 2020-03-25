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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        ListNode *tail = head;
        for (int i = 1; i < k; i++) {
            tail = tail->next;
            if (tail == NULL) return head;
        }
        ListNode *left = tail->next;
        tail->next = NULL;
        ListNode *newHead = tail;
        tail = head;
        while (head && head != newHead) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = newHead->next;
            newHead->next = tmp;
        }
        tail->next = reverseKGroup(left, k);
        return newHead;
    }
};
