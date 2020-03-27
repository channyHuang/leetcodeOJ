class Solution {
public:
    class Node {
    public:
        int row;
        int col;
        Node(int _r = 0, int _c = 0) {
            row = _r;
            col = _c;
        }
    };

    Solution(int n_rows, int n_cols) {
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                nodes.push_back(Node(i, j));
            }
        }
        rows = n_rows;
        cols = n_cols;
        count = n_rows * n_cols;
    }
    
    vector<int> flip() {
        vector<int> res;
        if (count <= 0) return res; 
        int idx = rand() % count;
        res.push_back(nodes[idx].row);
        res.push_back(nodes[idx].col);
        Node tmp = Node(nodes[idx].row, nodes[idx].col);
        nodes[idx] = Node(nodes[count - 1].row, nodes[count - 1].col);
        nodes[count - 1] = Node(tmp.row, tmp.col);
        count--;
        return res;
    }
    
    void reset() {
        count = rows * cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                nodes[i * cols + j] = Node(i, j);
            }
        }
    }

private:
    vector<Node> nodes;
    int count;
    int rows;
    int cols;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
