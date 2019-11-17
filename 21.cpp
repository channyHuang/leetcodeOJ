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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *endRes = NULL;
        ListNode *p = l1;
        ListNode *q = l2;
        while (p != NULL && q != NULL) {
            if (p->val <= q->val) {
                //addNode(res, endRes, p->val);
                if (res == NULL) {
            res = new ListNode(p->val);
            endRes = res;
        } else {
            endRes->next = new ListNode(p->val);
            endRes = endRes->next;
        }
                p = p->next;
            } else {
                //addNode(res, endRes, q->val);
                if (res == NULL) {
            res = new ListNode(q->val);
            endRes = res;
        } else {
            endRes->next = new ListNode(q->val);
            endRes = endRes->next;
        }
                q = q->next;
            }
        }

        while (p != NULL) {
                //addNode(res, endRes, p->val);
                if (res == NULL) {
            res = new ListNode(p->val);
            endRes = res;
        } else {
            endRes->next = new ListNode(p->val);
            endRes = endRes->next;
        }
                p = p->next;
            }

            while (q != NULL) {
                //addNode(res, endRes, q->val);
                if (res == NULL) {
            res = new ListNode(q->val);
            endRes = res;
        } else {
            endRes->next = new ListNode(q->val);
            endRes = endRes->next;
        }
                q = q->next;
            }

        return res;
    }

    void addNode(ListNode *res, ListNode *endRes, int value) {
        if (res == NULL) {
            res = new ListNode(value);
            endRes = res;
        } else {
            endRes->next = new ListNode(value);
            endRes = endRes->next;
        }
    }
};
