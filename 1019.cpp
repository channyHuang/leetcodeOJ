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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        if (head == NULL) return res;
        if (head->next == NULL) {
            res.push_back(0);
            return res;
        }
        vector<int> num;
        int lastPos = 0;
        int stPos = 0;
        num.push_back(head->val);
        res.push_back(0);
        ListNode *node = head->next;
        while (node != NULL) {
            num.push_back(node->val);
            res.push_back(0);
            node = node->next;

            lastPos++;
            if (num[lastPos] > num[lastPos - 1]) {
                res[lastPos - 1] = num[lastPos];
                for (int i = lastPos - 2; i >= 0; i--) {
                    if (res[i] != 0) continue;
                    if (num[i] >= num[i + 1] && num[i] < num[lastPos]) {
                        res[i] = num[lastPos];
                        continue;
                    }
                    if (num[i] > num[lastPos]) break;
                }
            }
        }
        return res;
    }
};
