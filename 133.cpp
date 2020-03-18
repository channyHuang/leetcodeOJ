/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node *nodes[105];

    Node* cloneGraph(Node* node) {
        //节点数介于 1 到 100 之间
        for (int i = 0; i < 105; i++) nodes[i] = NULL;
        return clone(node);
    }

    Node *clone(Node *root) {
        if (root == NULL) return NULL;
        if (nodes[root->val] == NULL) nodes[root->val] = new Node(root->val);
        for (int i = 0; i < root->neighbors.size(); i++) {
            if (nodes[root->neighbors[i]->val] == NULL) {
                nodes[root->neighbors[i]->val] = clone(root->neighbors[i]);
            }
            nodes[root->val]->neighbors.push_back(nodes[root->neighbors[i]->val]);
        }
        return nodes[root->val];
    }
};
