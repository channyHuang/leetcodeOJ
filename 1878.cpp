class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<int> smallheap;
        int hlen = 0;
        int minn = 1, maxn = (std::min(row, col) >> 1);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (hasSame(smallheap, grid[i][j])) continue;
                if (hlen < 3) {
                    smallheap.push_back(grid[i][j]);
                    up(smallheap, hlen);
                    hlen++;
                } else {
                    if (grid[i][j] <= smallheap[0]) continue;
                    smallheap[0] = grid[i][j];
                    down(smallheap, 0);
                }
            }
        }
        int sum = 0;
        for (int l = minn; l <= maxn; ++l) {
            for (int i = 0; i < row; ++i) {
                if (i + l + l >= row) break;
                for (int j = l; j < col; ++j) {
                    if (j + l >= col) break;
                    sum = getSum(grid, i, j, l);

                    if (hasSame(smallheap, sum)) continue;

                    if (hlen < 3) {
                        smallheap.push_back(grid[i][j]);
                        up(smallheap, hlen);
                        hlen++;
                    } else {
                        if (sum <= smallheap[0]) continue;
                        smallheap[0] = sum;
                        down(smallheap, 0);
                    }
                }
            }
        }
        if (hlen <= 1) return smallheap;
        sort(smallheap.begin(), smallheap.end());
        int tmp = smallheap[0];
        smallheap[0] = smallheap[hlen - 1];
        smallheap[hlen - 1] = tmp;
        return smallheap;
    }

    void up(vector<int> &smallheap, int idx) {
        if (idx == 0) return;
        if (smallheap[idx] >= smallheap[0]) return;
        if (idx == 1) return;
        int tmp = smallheap[0];
        smallheap[0] = smallheap[idx];
        smallheap[idx] = tmp;
    }

    void down(vector<int> &smallheap, int idx) {
        if (idx != 0) return;
        if (smallheap[0] <= smallheap[1] && smallheap[0] <= smallheap[2]) return;
        int sidx = 0;
        if (smallheap[1] <= smallheap[2]) sidx = 1;
        else sidx = 2;
        int tmp = smallheap[0];
        smallheap[0] = smallheap[sidx];
        smallheap[sidx] = tmp;     
    }

    bool hasSame(vector<int> &smallheap, int target) {
        for (int i = 0; i < smallheap.size(); ++i) {
            if (smallheap[i] == target) return true;
        }
        return false;
    }

    int getSum(vector<vector<int>>& grid, int r, int c, int l) {
        int sum = grid[r][c] + grid[r + l + l][c];
        for (int i = 1; i < l; ++i) {
            sum += (grid[r + i][c - i] + grid[r + i][c + i]);
            sum += (grid[r + l + l - i][c - i] + grid[r + l + l - i][c + i]);
        }
        sum += grid[r + l][c - l] + grid[r + l][c + l];
        return sum;
    }

private:
    int row, col;
};
