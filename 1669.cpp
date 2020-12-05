/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pre = list1;
        ListNode* next = list1;
        ListNode* tail2 = list2;
        b -= (a - 1);
        while (a > 1) {
            pre = pre->next;
            a--;
        }
        next = pre->next;
        while (b) {
            next = next->next;
            b--;
        }
        pre->next = list2;
        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }
        if (next != nullptr) {
            tail2->next = next;
        }
        return list1;
    }
};
