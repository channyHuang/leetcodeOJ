class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        vector<int> res;
        if (w * w == area) {
            res.push_back(w);
            res.push_back(w);
            return res;
        } else if (w * (w + 1) == area) {
            res.push_back(w + 1);
            res.push_back(w);          
            return res;
        } else {
            for (int x = w; x > 0; x--) {
                if (area % x == 0) {
                    res.push_back(area / x);
                    res.push_back(x);                 
                    return res;
                }
            }
        }
        return res;
    }
};
