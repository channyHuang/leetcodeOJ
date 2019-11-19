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
    void deleteNode(ListNode* node) {
        //阅读理解+1
        ListNode *curNode = node;
        while (curNode->next != NULL) {
            curNode->val = curNode->next->val;
            if (curNode->next->next == NULL) {
                ListNode *pDel = curNode->next;
                curNode->next = NULL;
                delete pDel;
                break;
            } else {
                curNode = curNode->next;
            }
        }
    }
};
