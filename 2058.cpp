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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res = {-1, -1};
        if (head == nullptr || head->next == nullptr) {
            return res;
        }
        vector<int> index;
        int idx = 1;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur->next != nullptr) {
            if (pre->val > cur->val && cur->next->val > cur->val) {
                index.push_back(idx);
            } else if (pre->val < cur->val && cur->next->val < cur->val) {
                index.push_back(idx);
            }
            cur = cur->next;
            pre = pre->next;
            idx++;
        }
        if (index.size() < 2) return res;
        res[0] = index[1] - index[0];
        res[1] = index[index.size() - 1] - index[0];
        for (int i = 1; i < index.size(); ++i) {
            res[0] = std::min(res[0], index[i] - index[i - 1]);
        }
        return res;
    }
};
