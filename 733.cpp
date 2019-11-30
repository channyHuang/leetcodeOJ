class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res = image;
        int row = image.size();
        if (row <= 0) return res;
        int col = image[0].size();

        changeColor(res, sr, sc, res[sr][sc], newColor, row, col);
        return res;
    }

    void changeColor(vector<vector<int>>& res, int sr, int sc, int oldColor, int newColor, int row, int col) {
        if (res[sr][sc] == newColor) return;
        res[sr][sc] = newColor;
        if (sr > 0 && res[sr - 1][sc] == oldColor) changeColor(res, sr - 1, sc, oldColor, newColor, row, col);
        if (sr < row - 1 && res[sr + 1][sc] == oldColor) changeColor(res, sr + 1, sc, oldColor, newColor, row, col);
        if (sc > 0 && res[sr][sc - 1] == oldColor) changeColor(res, sr, sc - 1, oldColor, newColor, row, col);
        if (sc < col - 1 && res[sr][sc + 1] == oldColor) changeColor(res, sr, sc + 1, oldColor, newColor, row, col); 
    }
};
