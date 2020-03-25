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
    class Node {
    public:
        ListNode *node;
        int sum;
        Node(ListNode *_node = NULL, int _sum = 0) {
            node = _node;
            sum = _sum;
        }       
    };

    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return (head->val == 0 ? NULL : head);
        map<int, ListNode *> maps;
        map<int, ListNode *>::iterator itr;
        
        while ((head != NULL) && (head->val == 0)) head = head->next;
        ListNode *node = head;
        if (node == NULL) return NULL;
        head = NULL;
        ListNode *pre = NULL;
        int sum = 0;
        while (node) {
            if (node->val == 0) {
                if (pre) {
                    pre->next = node->next;
                }
                node = node->next;
                continue;
            }
            sum += node->val;
            if (sum == 0) {
                head = NULL;
                node = node->next;
                maps.clear();
                pre = NULL;
                continue;
            }
            if (head == NULL) {
                head = node;
            }
            itr = maps.find(sum);
            if (itr == maps.end()) {
                ListNode *tmp = node;
                maps.insert(pair<int, ListNode *>(sum, tmp));
            } else {
                itr->second->next = node->next;
                maps.clear();
                sum = 0;
                node = head;
                pre = NULL;
                continue;
            }
            pre = node;
            node = node->next;
        }
        return head;
    }
};
