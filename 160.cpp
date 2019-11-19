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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        bool isP = false;

        ListNode *p = headA, *q = headB;
        while (p->next != NULL && q->next != NULL) {
            p = p->next;
            q = q->next;
        }

        if (p->next == NULL) {
            p = headB;
            isP = true;
        }
        else if (q->next == NULL) q = headA;

        while (p->next != NULL && q->next != NULL) {
            p = p->next;
            q = q->next;
        }

        if (isP && q->next == NULL) q = headA;
        else if (!isP && p->next == NULL) p = headB;
        

        while (p != NULL && q != NULL) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};
