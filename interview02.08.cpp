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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *pre = head;
        ListNode *tail = head;
        do {
            pre = pre->next;
            tail = tail->next;  
            if (tail == nullptr) return nullptr;
            tail = tail->next;
            if (tail == nullptr) return nullptr;
            if (pre == tail) break;
        } while (tail != nullptr);
        if (tail == nullptr) return nullptr;
        pre = head;
        while (pre != tail) {
            pre = pre->next;          
            tail = tail->next;
        }
        return pre;
    }
};
