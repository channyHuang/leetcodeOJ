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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode *> res;
        if (root == NULL) {
            for (int i = 0; i < k; i++) res.push_back(NULL);
            return res;
        }
        ListNode *node = root;
        int len = 1;
        while (node->next != NULL) {
            node = node->next;
            len++;
        }
        int count = len / k;
        int left = len % k;
        while (root != NULL) {
            ListNode *node = root;
            int tmp = 0;
            if (left) {               
                tmp = count;
                while (tmp && root->next) {
                    root = root->next;
                    tmp--;
                }
                left--;        
            } else {
                tmp = count - 1;
                while (tmp && root->next) {
                    root = root->next;
                    tmp--;
                }
            }
            ListNode *tail = root;
            root = root->next;
            tail->next = NULL;
            res.push_back(node);
        }
        while (res.size() < k) res.push_back(NULL);
        return res;
    }
};
