class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> vec;
        vec.push_back(1);
        if (numRows <= 0) return res;
        res.push_back(vec);
        if (numRows == 1) return res;

        for (int n = 2; n <= numRows; n++) {
            vector<int> line;
            int lenRes = res.size();
            int lenLast = res[lenRes - 1].size();
            line.push_back(1);
            for (int i = 1; i < lenLast; i++) {
                line.push_back(res[lenRes - 1][i] + res[lenRes - 1][i - 1]);
            }
            line.push_back(1);
            res.push_back(line);
        }
        return res;
    }
};
