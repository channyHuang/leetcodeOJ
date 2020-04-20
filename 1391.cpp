class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        bool used[305][305];
        memset(used, 0, sizeof(used));
        return search(grid, rows, cols, used, 0, 0);
    }

    bool search(vector<vector<int>>& grid, int rows, int cols, bool used[305][305], int r, int c) {
        if (r == rows - 1 && c == cols - 1) return true;
        used[r][c] = true;
        bool flag = false;
        switch(grid[r][c]) {
        case 1:
            if (c - 1 >= 0 && !used[r][c - 1] && (grid[r][c - 1] == 4 || grid[r][c - 1] == 6 || grid[r][c - 1] == 1)) {
                flag = search(grid, rows, cols, used, r, c - 1);
                if (flag) return true;
            }
            if (c + 1 < cols && !used[r][c + 1] && (grid[r][c + 1] == 3 || grid[r][c + 1] == 5 || grid[r][c + 1] == 1)) {
                flag = search(grid, rows, cols, used, r, c + 1);
                if (flag) return true;
            }
            break;          
        case 2:
            if (r - 1 >= 0 && !used[r - 1][c] && (grid[r - 1][c] == 3 || grid[r - 1][c] == 4 || grid[r - 1][c] == 2)) {
                flag = search(grid, rows, cols, used, r - 1, c);
                if (flag) return true;
            }
            if (r + 1 < rows && !used[r + 1][c] && (grid[r + 1][c] == 5 || grid[r + 1][c] == 6  || grid[r + 1][c] == 2)) {
                flag = search(grid, rows, cols, used, r + 1, c);
                if (flag) return true;
            }
            break;
        case 3:
            if (c - 1 >= 0 && !used[r][c - 1] && (grid[r][c - 1] == 4 || grid[r][c - 1] == 6 || grid[r][c - 1] == 1)) {
                flag = search(grid, rows, cols, used, r, c - 1);
                if (flag) return true;
            }
            if (r + 1 < rows && !used[r + 1][c] && (grid[r + 1][c] == 5 || grid[r + 1][c] == 6 || grid[r + 1][c] == 2)) {
                flag = search(grid, rows, cols, used, r + 1, c);
                if (flag) return true;
            }
            break;
        case 4:
            if (c + 1 < cols && !used[r][c + 1] && (grid[r][c + 1] == 3 || grid[r][c + 1] == 5 || grid[r][c + 1] == 1)) {
                flag = search(grid, rows, cols, used, r, c + 1);
                if (flag) return true;
            }
            if (r + 1 < rows && !used[r + 1][c] && (grid[r + 1][c] == 5 || grid[r + 1][c] == 6 || grid[r + 1][c] == 2)) {
                flag = search(grid, rows, cols, used, r + 1, c);
                if (flag) return true;
            }
            break;
        case 5:
            if (r - 1 >= 0 && !used[r - 1][c] && (grid[r - 1][c] == 3 || grid[r - 1][c] == 4 || grid[r - 1][c] == 2)) {
                flag = search(grid, rows, cols, used, r - 1, c);
                if (flag) return true;
            }
            if (c - 1 >= 0 && !used[r][c - 1] && (grid[r][c - 1] == 4 || grid[r][c - 1] == 6 || grid[r][c - 1] == 1)) {
                flag = search(grid, rows, cols, used, r, c - 1);
                if (flag) return true;
            }
            break;
        case 6:
            if (r - 1 >= 0 && !used[r - 1][c] && (grid[r - 1][c] == 3 || grid[r - 1][c] == 4 || grid[r - 1][c] == 2)) {
                flag = search(grid, rows, cols, used, r - 1, c);
                if (flag) return true;
            }
            if (c + 1 < cols && !used[r][c + 1] && (grid[r][c + 1] == 3 || grid[r][c + 1] == 5 || grid[r][c + 1] == 1)) {
                flag = search(grid, rows, cols, used, r, c + 1);
                if (flag) return true;
            }
            break;
        default:
            break;
        }
        return false;
    }
};
