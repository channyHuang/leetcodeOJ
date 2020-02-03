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
        ListNode *res;

        while (1) {
            if (head == NULL) return NULL;
            if (head->next == NULL) return head;
            
            if (head->val != head->next->val) {
                res = head;
                ListNode *tail = res;

                while (1) {
                    ListNode *pre = tail->next;
                    if (pre == NULL) return res;
                    ListNode *next = pre->next;
                    if (next == NULL) return res;
                    if (next->val == pre->val) {
                        while (1) {
                            next = next->next;
                            if (next == NULL || next->val != pre->val) break;
                        }
                        tail->next = next;
                    } else {
                        tail = pre;
                    }
                }

                return res;
            } else {
                ListNode *next = head->next;           
                while (next && head->val == next->val) next = next->next;
                head = next;
            }
        }
              
        return res;
    }
};