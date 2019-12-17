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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        if (head->next == NULL) return true;
        if (head->next->next == NULL) {
            return (head->next->val == head->val);
        }
        bool odd = true;
        ListNode *newNode = head, *halfNode = head->next, *curNode = head->next->next;
        ListNode *tmpNode = NULL;
        head->next = NULL;
        while (curNode->next) {
            tmpNode = halfNode;
            halfNode = halfNode->next;
            curNode = curNode->next;
            if (curNode->next) {
                curNode = curNode->next;
            }
            else {
                odd = false;
                break;
            }

            tmpNode->next = newNode;
            newNode = tmpNode;
        }

        if (odd) {
            halfNode = halfNode->next;
        } else {
            tmpNode->next = newNode;
            newNode = tmpNode;
        }

        curNode = newNode;
        while (halfNode && curNode) {
            if (curNode->val != halfNode->val) return false;
            halfNode = halfNode->next;
            curNode = curNode->next;
        }
        return true;
    }
};
