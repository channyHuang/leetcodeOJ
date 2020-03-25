/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* nodes[1005];
        map<Node *, int> maps;
        map<Node *, int>::iterator itr;
        Node *ori = head;
        int pos = 0;
        while (ori) {
            nodes[pos] = new Node(ori->val);
            if (pos) nodes[pos - 1]->next = nodes[pos];
            Node *tmp = ori;
            maps.insert(pair<Node *, int>(tmp, pos));
            ori = ori->next;
            pos++;
        }
        ori = head;
        int idx = 0;
        while (ori) {
            if (ori->random == NULL) {
                idx++;
                ori = ori->next;
                continue;
            }
            itr = maps.find(ori->random);
            if (itr == maps.end()) {
                idx++;
                ori = ori->next;
                continue;
            }
            nodes[idx]->random = nodes[itr->second];
            idx++;
            ori = ori->next;
        }
        return nodes[0];
    }
};
