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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *curNode = head->next;
        ListNode *res = new ListNode(head->val);
        ListNode *endRes = res;
        while (curNode != NULL) {
            if (curNode->val != endRes->val) {
                endRes->next = new ListNode(curNode->val);
                endRes = endRes->next;
            }
            curNode = curNode->next;
        }
        return res;
    }
};
