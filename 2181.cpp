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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *cur = head->next;
        int count = 0;
        ListNode *root = nullptr;
        ListNode *tail = root;
        while (cur != nullptr) {
          while (cur != nullptr && cur->val != 0) {
            count += cur->val;
            cur = cur->next;
          }
          if (root == nullptr) {
            root = new ListNode(count);
            tail = root;
          }
          else {
            tail->next = new ListNode(count);
            tail = tail->next;
          }
          count = 0;
          if (cur != nullptr) cur = cur->next;
        }
        return root;
    }
};
