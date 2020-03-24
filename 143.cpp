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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast) {
            fast = fast->next;
            if (fast == NULL) break;
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *half = slow->next;
        slow->next = NULL;
        stack<ListNode *> st;
        while (half) {
            ListNode *tmp = half;
            half = half->next;
            tmp->next = NULL;
            st.push(tmp);
        }
        fast = head;
        while (!st.empty()) {
            ListNode *node = st.top();
            st.pop();
            node->next = fast->next;
            fast->next = node;
            fast = node->next;
        }
        return;
    }
};
