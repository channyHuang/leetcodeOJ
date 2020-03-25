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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int len = 1;
        ListNode *tail = head;

        while (tail->next) {
            tail = tail->next;
            len++;
        }
        k %= len;
        if (k == 0) return head;
        tail->next = head;

        int step = len - k;
        ListNode *pre = head;
        while (step) {
            pre = head;
            head = head->next;
            step--;
        }
        pre->next = NULL;
        return head;
    }
};
