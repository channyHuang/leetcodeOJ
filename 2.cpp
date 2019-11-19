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
        ListNode *res = NULL, *resEnd = NULL;
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *a1 = l1, *a2 = l2;
        int add = 0;
        int stNum = addSum(a1->val + a2->val, add);

        res = new ListNode(stNum);
        resEnd = res;
        while (a1->next != NULL && a2->next != NULL) {
            stNum = addSum(a1->next->val + a2->next->val + add, add);
            resEnd->next = new ListNode(stNum);
            resEnd = resEnd->next;
            a1 = a1->next;
            a2 = a2->next;
        }

        while (a1->next != NULL) {
            stNum = addSum(a1->next->val + add, add);
            resEnd->next = new ListNode(stNum);
            resEnd = resEnd->next;
            a1 = a1->next;
        }

        while (a2->next != NULL) {
            stNum = addSum(a2->next->val + add, add);
            resEnd->next = new ListNode(stNum);
            resEnd = resEnd->next;
            a2 = a2->next;
        }

        if (add) resEnd->next = new ListNode(1);

        return res;
    }

    int addSum(int sum, int &add) {
        if (sum >= 10) {
            add = 1;
            sum %= 10;
        } else {
            add = 0;
        }
        return sum;
    }
};
