class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        int used[10] = {0};
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (grid[i][j] != 5) continue;
                
                if (grid[i-1][j-1] + grid[i+1][j+1] != 10) continue;           
                if (grid[i-1][j] + grid[i+1][j] != 10) continue;
                if (grid[i-1][j+1] + grid[i+1][j-1] != 10) continue;
                if (grid[i][j-1] + grid[i][j+1] != 10) continue;
                if (grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] != 15) continue;
                if (grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1] != 15) continue;
                if (grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1] != 15) continue;
                if (grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1] != 15) continue;
                bool flag = true;
                for (int i = 0; i < 10; i++) used[i] = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for(int y = j - 1; y <= j + 1; y++) {
                        if (grid[x][y] <= 0 || grid[x][y] >= 10 || used[grid[x][y]]) {
                            flag = false;
                            break;
                        }
                        used[grid[x][y]] = 1;
                    }
                    if (!flag) break;
                }
                if (flag) res++;
            }
        }
        return res;
    }
};
