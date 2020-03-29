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

    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = -1;
        vector<Node> land[2];
        vector<vector<int>> dis;
        for (int i = 0; i < rows; i++) {
            vector<int> subdis;
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    land[0].push_back(Node(i, j));
                }
                subdis.push_back(grid[i][j]);
            }
            dis.push_back(subdis);
        }
        if (land[0].size() == 0 || land[0].size() == rows * cols) return -1;
        int pos = 0;
        int nextPos = 1;

        while (land[pos].size() != 0) {
            land[nextPos].clear();
            for (int i = 0; i < land[pos].size(); i++ ) {
                int r = land[pos][i].row;
                int c = land[pos][i].col;
                if (r > 0 && dis[r - 1][c] == 0) {
                    dis[r - 1][c] = dis[r][c] + 1;
                    land[nextPos].push_back(Node(r - 1, c));
                    if (res < dis[r - 1][c]) res = dis[r - 1][c];
                }
                if (r < rows - 1 && dis[r + 1][c] == 0) {
                    dis[r + 1][c] = dis[r][c] + 1;
                    land[nextPos].push_back(Node(r + 1, c));
                    if (res < dis[r + 1][c]) res = dis[r + 1][c];
                }
                if (c > 0 && dis[r][c - 1] == 0) {
                    dis[r][c - 1] = dis[r][c] + 1;
                    land[nextPos].push_back(Node(r, c - 1));
                    if (res < dis[r][c - 1]) res = dis[r][c - 1];
                }
                if (c < cols - 1 && dis[r][c + 1] == 0) {
                    dis[r][c + 1] = dis[r][c] + 1; 
                    land[nextPos].push_back(Node(r, c + 1));
                    if (res < dis[r][c + 1]) res = dis[r][c + 1];
                }
            }
            pos = nextPos;
            nextPos = 1 - pos;
        }
        return res - 1;
    }
};
