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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        if (head == NULL ) return res;
        ListNode *curNode = head;
        while (curNode) {
            res = (res << 1) + curNode->val;
            curNode = curNode->next;
        }
        return res;
    }
};
