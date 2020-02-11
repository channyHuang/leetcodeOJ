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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *larger = NULL;
        ListNode *tailLarger = NULL;
        ListNode *res = NULL;
        ListNode *tailRes = NULL;
        ListNode *curNode = head;
        while (curNode != NULL) {
            if (curNode->val < x) {
                if (res == NULL) {
                    res = curNode;
                    tailRes = res;
                } else {
                    tailRes->next = curNode;
                    tailRes = tailRes->next;
                }
                curNode = curNode->next;
                tailRes->next = NULL;
            } else if (curNode->val >= x) {
                if (larger == NULL) {
                    larger = curNode;
                    tailLarger = larger;
                } else {
                    tailLarger->next = curNode;
                    tailLarger = tailLarger->next;
                }
                curNode = curNode->next;
                tailLarger->next = NULL;
            }
        }
        if (res != NULL) {
            tailRes->next = larger;
            return res;
        } else return larger;
    }
};