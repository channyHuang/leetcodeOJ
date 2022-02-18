/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        // len >= 2
        ListNode *cur = head;
        ListNode *pre = cur;
        ListNode *tail = head->next;
        while (tail != nullptr) {
            tail = tail->next;
            pre = cur;
            cur = cur->next;
            if (tail != nullptr) tail = tail->next;
        }
        // delete cur
        pre->next = cur->next;
        return head;
    }
};

