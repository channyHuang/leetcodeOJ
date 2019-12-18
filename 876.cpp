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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        if (head->next->next == NULL) return head->next;
        ListNode *half = head->next, *curNode = head->next->next;
        while (curNode->next) {
            half = half->next;
            curNode = curNode->next;
            if (curNode->next == NULL) break;
            curNode = curNode->next;
        }
        return half;
    }
};
