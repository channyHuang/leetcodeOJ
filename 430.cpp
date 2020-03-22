/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *res = head;
        Node *next = res;
        while (next != NULL) {
            check(next);
            next = next->next;
        }
        return res;
    }

    void check(Node *node) {
        if (node->child == NULL) return;
        Node *head = node->child;
        Node *tail = head;
        while (tail->next) tail = tail->next;
        Node *next = node->next;
        node->next = head;
        head->prev = node;
        node->child = NULL;
        if (next == NULL) return;
        tail->next = next;
        next->prev = tail;
        
    }
};
