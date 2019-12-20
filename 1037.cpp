class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //same
        if (points[0][0] == points[1][0] && points[0][1] == points[1][1]) return false;
        if (points[2][0] == points[1][0] && points[2][1] == points[1][1]) return false;
        if (points[0][0] == points[2][0] && points[0][1] == points[2][1]) return false; 
        // vertical
        if (points[0][0] == points[1][0]) return points[2][0] != points[1][0];
        if (points[0][0] == points[2][0]) return points[0][0] != points[1][0];
        if (points[2][0] == points[1][0]) return points[0][0] != points[1][0];
        //horizental
        if (points[0][1] == points[1][1]) return points[2][1] != points[0][1];
        if (points[0][1] == points[2][1]) return points[1][1] != points[0][1];
        if (points[2][1] == points[1][1]) return points[2][1] != points[0][1];
        // y1 - y0 / x1 - x0 = y2 - y1 / x 2 - x1 
        return ((points[2][0] - points[0][0]) * (points[1][1] - points[0][1])) != ((points[1][0] - points[0][0]) * (points[2][1] - points[0][1]));
    }
};
