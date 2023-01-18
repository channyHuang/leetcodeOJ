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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *res = head;
        int targetlen = 2; 
        ListNode *lasttail = head;    
        ListNode *startptr = head->next;
        while (startptr != nullptr) {
            int curlen = 1;
            ListNode *curptr = startptr;
            while (curptr->next != nullptr && curlen < targetlen) {
              curptr = curptr->next;
              curlen++;
            }
            //cout << targetlen << " startptr = " << startptr->val << ", endptr = " << curptr->val << endl; 
            if (curlen & 1) {
              lasttail = curptr;
              startptr = lasttail->next;
              targetlen++;
              continue;
            }
            
            ListNode *newtail = reverse(lasttail, curptr);
            startptr = newtail->next;
            lasttail = newtail;
            curptr = startptr;
            targetlen++;
        }
        return res;
    }

    ListNode* reverse(ListNode *lasttail, ListNode *tail) {
        ListNode *newtail = lasttail->next;
        ListNode *head = lasttail;
        ListNode *node = newtail->next;
        newtail->next = tail->next;
        ListNode *targettail = newtail;
        while (node != newtail && node != newtail->next) {
          ListNode *nextnode = node->next;
          head->next = node;
          node->next = targettail;
          targettail = node;
          node = nextnode;
        }
        return newtail;
    }
};

