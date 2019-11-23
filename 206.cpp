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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* res = head;
        ListNode* curNode = head->next;
        while (curNode != NULL) {
            head->next = curNode->next;
            curNode->next = res;
            res = curNode;
            curNode = head->next;
        }
        return res;
    }
};
