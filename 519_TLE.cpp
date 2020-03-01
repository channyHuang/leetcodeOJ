class Solution {
public:
    int len;
    int rows;
    int cols;
    vector<vector<int>> vec;

    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        len = n_rows * n_cols;
        for (int i = 0; i < rows; i++) {
            vector<int> subvec;
            vec.push_back(subvec);
        }
    }
    
    vector<int> flip() {
        int r = rand() % len + 1;
        vector<int> res;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int k;
                for (k = 0; k < vec[i].size(); k++) {
                    if (vec[i][k] == j) break;
                }
                if (k == vec[i].size()) r--;
                if (r == 0) {                  
                    res.push_back(i);
                    res.push_back(j);
                    vec[i].push_back(j);
                    len--;
                    return res;
                }
            }
        }
        return res;
    }
    
    void reset() {
        len = rows * cols;
        
        for (int i = 0; i < rows; i++) {
            vector<int> subvec;
            vec[i].swap(subvec);
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
