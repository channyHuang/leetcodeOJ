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
    int count;
    ListNode *node;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        node = head;
        ListNode *curnode = head;
        count = 0;
        while (curnode) {
            count++;
            curnode = curnode->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        if (node == NULL) return 0;
        int idx = rand() % count;
        ListNode *curnode = node;
        while (idx) {
            curnode = curnode->next;
            idx--;
        }
        return curnode->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
