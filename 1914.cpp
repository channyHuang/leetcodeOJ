class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int halfrow = (row >> 1);
        int halfcol = (col >> 1);
        int minround = std::min(halfrow, halfcol);

        for (int r = 0; r < minround; ++r) {
            int rowcount = (row - r * 2), colcount = (col - r * 2);
            int total = (rowcount + colcount - 2) * 2;
            int left = k % total;

            if (left == 0) continue;
            
			vector<int> head;
			int curr, curc;
			for (int idx = 0; idx < left; idx++) {
				getGrid(idx, row, col, r, curr, curc);
				head.push_back(grid[curr][curc]);
			}
			for (int idx = left; idx < total; ++idx) {
				getGrid(idx, row, col, r, curr, curc);
				int tmp = grid[curr][curc];
				getGrid(idx - left, row, col, r, curr, curc);
				grid[curr][curc] = tmp;
			}
			for (int idx = 0; idx < left; ++idx) {
				getGrid((idx - left + total) % total, row, col, r, curr, curc);
				grid[curr][curc] = head[idx];
			}
        }
        return grid;
    }

    void getGrid(int index, int r, int c, int st, int& curr, int& curc) {
        int count = c - 2 * st;
        if (index < count) {
            curr = st;
            curc = st + index;
            return;
        }
        index -= count;
        count = r - 2 * st - 1;
        if (index < count) {
            curr = st + index + 1;
            curc = c - st - 1;
            return;
        }
        index -= count;
        count = c - 2 * st - 1;
        if (index < count) {
            curr = r - st - 1;
            curc = c - st - index - 2;
            return;
        }
        index -= count;
        curr = r - st - index - 2;
        curc = st;
    }
};

