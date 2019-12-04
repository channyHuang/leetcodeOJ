/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node *root = NULL;
        if (quadTree1 == NULL && quadTree2 == NULL) return root;
        if (quadTree1 == NULL) return quadTree2;
        if (quadTree2 == NULL) return quadTree1;
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            return new Node(quadTree1->val | quadTree2->val, true, NULL, NULL, NULL, NULL);
        } else if (quadTree1->isLeaf) {
            if (quadTree1->val) return quadTree1;
            else return quadTree2;
        } else if (quadTree2->isLeaf) {
            if (quadTree2->val) return quadTree2;
            else return quadTree1;
        } else {
            root = new Node(false, false, NULL, NULL, NULL, NULL);
            root->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            root->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            root->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            root->topRight = intersect(quadTree1->topRight, quadTree2->topRight);

            if (root->bottomLeft == NULL && root->bottomRight == NULL && root->topLeft == NULL && root->topRight == NULL) root->isLeaf = true;
            if (root->bottomLeft->isLeaf && root->bottomRight->isLeaf && root->topLeft->isLeaf && root->topRight->isLeaf) {
                if (root->bottomLeft->val == root->bottomRight->val && root->bottomLeft->val == root->topLeft->val && root->bottomLeft->val == root->topRight->val) {
                    root->val = root->bottomLeft->val;
                    root->isLeaf = true;
                    root->bottomLeft = NULL;
                    root->bottomRight = NULL;
                    root->topLeft = NULL;
                    root->topRight = NULL;
                }
            }
        }
        return root;
    }
};
