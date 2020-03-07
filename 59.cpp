class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            vector<int> subres;
            subres.resize(n);
            res.push_back(subres);
        }
        int i = 0, j = 0;
        int dir = 0; //0: right, 1: down, 2: left, 3: up
        int pos = 1;
        int maxn = n * n;
        while (pos <= maxn) {
            res[i][j] = pos;
            if (pos == maxn) break;
            pos++;
            
            switch(dir) {
            case 0: 
                if (j + 1 >= n || res[i][j + 1] != 0) {
                    dir = 1;
                    i++;
                } else j++;
                break;
            case 1:
                if (i + 1 >= n || res[i + 1][j] != 0) {
                    dir = 2;
                    j--;
                } else i++;
                break;
            case 2:
                if (j - 1 < 0 || res[i][j - 1] != 0) {
                    dir = 3;
                    i--;
                } else j--;
                break;
            case 3:
                if (i - 1 < 0 || res[i - 1][j] != 0) {
                    dir = 0;
                    j++;
                } else i--;
                break;
            default:
                break;
            }
        }
        return res;
    }
};
