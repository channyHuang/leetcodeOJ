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
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
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
    Node* construct(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        return construct(grid, 0, rows - 1, 0, cols - 1);
    }

    Node* construct(vector<vector<int>>& grid, int strow, int endrow, int stcol, int endcol) {
        if (strow > endrow || stcol > endcol) return NULL;
        int midrow = (strow + endrow) / 2;
        int midcol = (stcol + endcol) / 2;
        Node *root = new Node();
        if (strow == endrow) {
            root->isLeaf = true;   
            root->val = grid[strow][stcol];    
            return root;
        }
        root->topLeft = construct(grid, strow, midrow, stcol, midcol);
        root->topRight = construct(grid, strow, midrow, midcol + 1, endcol);
        root->bottomLeft = construct(grid, midrow + 1, endrow, stcol, midcol);
        root->bottomRight = construct(grid, midrow + 1, endrow, midcol + 1, endcol);
        if (root->topLeft->isLeaf && root->topRight->isLeaf && root->bottomLeft->isLeaf  && root->bottomRight->isLeaf 
            && (root->topLeft->val == root->topRight->val && root->topLeft->val == root->bottomLeft->val  && root->topLeft->val == root->bottomRight->val)) {
            root->isLeaf = true;
            root->val = root->topLeft->val;
            root->topLeft = NULL;
            root->topRight = NULL;
            root->bottomLeft = NULL;
            root->bottomRight = NULL;
        }
        return root;
    } 
};
