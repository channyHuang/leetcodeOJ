class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        rows = heightMap.size();
        cols = heightMap[0].size();
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
        for (int i = 0; i < rows; i++) {
            qu.push(pair<int, int>(heightMap[i][0], fromIndex(i, 0)));
            qu.push(pair<int, int>(heightMap[i][cols - 1], fromIndex(i, cols - 1)));
            used[i][0] = true;
            used[i][cols - 1] = true;
        }
        for (int j = 0; j < cols; j++) {
            qu.push(pair<int, int>(heightMap[0][j], fromIndex(0, j)));
            qu.push(pair<int, int>(heightMap[rows - 1][j], fromIndex(rows - 1, j)));
            used[0][j] = true;
            used[rows - 1][j] = true;
        }
        int res = 0;
        while (!qu.empty()) {
            pair<int, int> cur = qu.top();
            qu.pop();
            int r, c;
            toIndex(cur.second, r, c);

            //cout << r << " " << c << " " << cur.first << endl;
            
            if (r > 0 && !used[r - 1][c]) {
                if (heightMap[r - 1][c] < cur.first) {
                    res += cur.first - heightMap[r - 1][c];
                    heightMap[r - 1][c] = max(heightMap[r - 1][c], cur.first);                    
                }
                qu.push(pair<int, int>(heightMap[r - 1][c], fromIndex(r - 1, c)));
                used[r - 1][c] = true;
            } 
            if (r < rows - 1 && !used[r + 1][c]) {
                if (heightMap[r + 1][c] < cur.first) {
                    res += cur.first - heightMap[r + 1][c];
                    heightMap[r + 1][c] = cur.first;                    
                }
                qu.push(pair<int, int>(heightMap[r + 1][c], fromIndex(r + 1, c)));
                used[r + 1][c] = true;
            }
            if (c > 0 && !used[r][c - 1]) {
                if (heightMap[r][c - 1] < cur.first) {
                    res += cur.first - heightMap[r][c - 1];
                    heightMap[r][c - 1] = cur.first;                    
                }
                qu.push(pair<int, int>(heightMap[r][c - 1], fromIndex(r, c - 1)));
                used[r][c - 1] = true;
            }
            if (c < cols - 1 && !used[r][c + 1]) {
                if (heightMap[r][c + 1] < cur.first) {
                    res += cur.first - heightMap[r][c + 1];
                    heightMap[r][c + 1] = cur.first;                    
                }
                qu.push(pair<int, int>(heightMap[r][c + 1], fromIndex(r, c + 1)));
                used[r][c + 1] = true;
            }
        }
        return res;
    }

    int fromIndex(int r, int c) {
        return r * cols + c;
    }
    void toIndex(int target, int &r, int &c) {
        r = target / cols;
        c = target % cols;
    }
private:
    int rows;
    int cols;
};
