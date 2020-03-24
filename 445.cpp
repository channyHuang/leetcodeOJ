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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *p = l1, *q = l2;
        while (p->next != NULL && q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        if (p->next == NULL && q->next == NULL) { //same length
            p = l1;
            q = l2;
            ListNode *preq = l2;
            while (p != NULL) {
                p->val += q->val;
                if (p->val >= 10) {
                    p->val -= 10;
                    if (q == l2) {
                        ListNode *head = new ListNode(1);
                        head->next = l2;
                        l2 = head;
                    } else {
                        preq->val += 1;
                    }
                }
                q->val = 0;
                preq = q;
                p = p->next;
                q = q->next;
            }
            l2 = delete0(l2);
            return addTwoNumbers(l1, l2);
        }
        
        if (p->next != NULL) { // l1 longer than l2
            q = p;
            p = l1;
            while (q->next) {
                p = p->next;
                q = q->next;
            }
            q = l2;
            ListNode *preq = q;
            while (p != NULL) {
                p->val += q->val;
                if (p->val >= 10) {
                    p->val -= 10;
                    if (q == l2) {
                        ListNode *head = new ListNode(1);
                        head->next = l2;
                        l2 = head;
                    } else {
                        preq->val += 1;
                    }
                }
                q->val = 0;
                preq = q;
                p = p->next;
                q = q->next;
            }
            l2 = delete0(l2);
            return addTwoNumbers(l1, l2);
        } 
        // l2 longer than l1
        p = q;
        q = l2;
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        p = l1;
        ListNode *prep = p;
        while (q != NULL) {
            q->val += p->val;
            if (q->val >= 10) {
                q->val -= 10;
                if (p == l1) {
                    ListNode *head = new ListNode(1);
                    head->next = l1;
                    l1 = head;
                } else {
                    prep->val += 1;
                }
            }
            p->val = 0;
            prep = p;
            p = p->next;
            q = q->next;
        }
        l1 = delete0(l1);
        return addTwoNumbers(l1, l2);
    }

    ListNode * delete0(ListNode *l) {
        while (l != NULL && l->val == 0) {
            ListNode *tmp = l;
            l = l->next;
            delete tmp;
        }
        return l;
    }
};
