class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res;
		int rows = grid.size();
		if (rows <= 0) return res;
		int cols = grid[0].size();
		if (cols <= 0) return res;
		
		//col i -> (i + k) % cols
		int counts[cols] = {0};
		int ret = k % cols;
		for (int i = cols - 1; i >= 0; i--) {
			counts[i] = k / cols;
			if (i + ret >= cols) counts[i]++;
			counts[i] %= rows;
		}
		
		for (int i = 0; i < rows; i++) {
			vector<int> subres;
			subres.resize(cols);
			res.push_back(subres);
		}
		
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				res[(i + counts[j]) % rows][(j + k) % cols] = grid[i][j];
			}
		}
		return res;
    }
};
