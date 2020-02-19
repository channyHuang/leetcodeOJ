class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int rows = grid.size();
		if (rows <= 0) return 0;
		int cols = grid[0].size();
		if (cols <= 0) return 0;
		vector<vector<int>> res;
		for (int i = 0; i < rows; i++) {
			vector<int> subres;
			subres.resize(cols);
			for (int j = 0; j < cols; j++) {
				subres[j] = 2147483647;
			}
			res.push_back(subres);
		}
		queue<pair<int, int>> qu;
		res[0][0] = grid[0][0];
		qu.push(pair(0, grid[0][0]));
		while (!qu.empty()) {
			pair<int, int> tmp = qu.front();
			qu.pop();
			int r = tmp.first / cols;
			int c = tmp.first % cols;
			int val = tmp.second;
			if (val > grid[r][c]) continue;
			if (r + 1 < rows) {
				if (res[r + 1][c] > res[r][c] + grid[r + 1][c]) {
					res[r + 1][c] = res[r][c] + grid[r + 1][c];
					qu.push(pair( (r + 1) * cols + c, res[r + 1][c]));
				}
			}
			if (c + 1 < cols) {
				if (res[r][c + 1] > res[r][c] + grid[r][c + 1]) {
					res[r][c + 1] = res[r][c] + grid[r][c + 1];
					qu.push(pair( r * cols + c + 1, res[r][c + 1]));
				}
			}	
		}
		return res[rows - 1][cols - 1];
    }
};
