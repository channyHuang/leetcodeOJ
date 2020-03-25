class MyLinkedList {
public:
    class Node {
    public:
        int val;
        Node *prev;
        Node *next;
        Node(int _val = 0) {
            val = _val;
            prev = NULL;
            next = NULL;
        }
    };
    Node *head;
    Node *tail;
    int count;

    /** Initialize your data structure here. */
    MyLinkedList() {
        count = 0;
        head = NULL;
        tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= count) return -1;
        Node *node;
        if (index <= count / 2) {
            node = head;
            while (index) {
                node = node->next;
                index--;
            }
        } else {
            index = count - index;
            node = tail;
            while (index > 1) {
                node = node->prev;
                index--;
            }
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (count == 0) {
            head = new Node(val);
            tail = head;
            count++;
            return;
        }
        Node *node = new Node(val);
        node->next = head;
        head->prev = node;
        head = head->prev;
        count++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (count == 0) {
            head = new Node(val);
            tail = head;
            count++;
            return;
        }
        Node *node = new Node(val);
        node->prev = tail;
        tail->next = node;
        tail = tail->next;
        count++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > count) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == count) {
            addAtTail(val);
            return;
        } 
        Node *node = new Node(val);
        Node *prenode;
        if (index <= count / 2) {
            prenode = head;
            while (index > 1) {
                prenode = prenode->next;
                index--;
            }
        } else {
            index = count - index;
            prenode = tail;
            while (index) {
                prenode = prenode->prev;
                index--;
            }
        }
        node->next = prenode->next;
        node->prev = prenode;
        prenode->next = node;
        if (node->next) {
            node->next->prev = node;
        }
        count++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= count) return;

        Node *prenode = NULL;
        //if (index <= count / 2) {
            prenode = head;
            while (index) {
                prenode = prenode->next;
                index--;
            }/*
        } else {
            index = count - index;
            prenode = tail;
            while (index > 1) {
                prenode = prenode->prev;
                index--;
            }
        }*/
            
        if (prenode->prev) prenode->prev->next = prenode->next;
        else head = prenode->next;
        if (prenode->next) prenode->next->prev = prenode->prev;
        else tail = prenode->prev;
        prenode->prev = NULL;
        prenode->next = NULL;
        delete prenode;
        
        count--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
