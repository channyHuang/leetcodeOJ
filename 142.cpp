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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            fast = fast->next;
            if (fast == NULL) return NULL;
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) return NULL;
        } while (slow != fast);
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
