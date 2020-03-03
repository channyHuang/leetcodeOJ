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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len <= 0) return NULL;
        while (len > 1) {
            for (int i = 0; i < len / 2; i++) {
                merge(lists, i, len - i - 1);
            }
            len = lists.size();
        }
        return lists[0];
    }

    void merge(vector<ListNode*>& lists, int i, int j) {
        ListNode *p1 = lists[i];
        ListNode *p2 = lists[j];

        if (p1 == NULL) {
            lists[i] = lists[j];
            lists.pop_back();
            return;
        }

        while (p2 != NULL) {
            if (p1->val > p2->val) {
                ListNode *node = p2;
                p2 = p2->next;
                node->next = p1;
                lists[i] = node;
                p1 = lists[i];   
            } else if (p1->next == NULL) {
                p1->next = p2;
                p2 = p2->next;
                p1 = p1->next;
                p1->next = NULL;
            } else if (p1->next->val > p2->val){
                ListNode *node = p2;
                p2 = p2->next;
                node->next = p1->next;
                p1->next = node;
            } else {
                p1 = p1->next;
            }
        }
        lists.pop_back();

    }
};
