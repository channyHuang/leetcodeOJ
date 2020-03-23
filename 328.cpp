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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode *oddTail = head;
        ListNode *nextNode = head->next;
        while (nextNode != NULL && nextNode->next != NULL) {
            ListNode *moveNode = nextNode->next;
            nextNode->next = moveNode->next;
            moveNode->next = oddTail->next;
            oddTail->next = moveNode;
            oddTail = oddTail->next;
            nextNode = nextNode->next;
        }
        return head;
    }
};
