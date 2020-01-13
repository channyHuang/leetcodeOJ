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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return NULL;
        ListNode *front = head;
        ListNode *tail = head;
        while (n--) {
            if (tail->next == NULL) return head->next;
            tail = tail->next;
        }

        while (tail->next != NULL) {
            front = front->next;
            tail = tail->next;
        }

        front->next = front->next->next;

        return head;
    }
};