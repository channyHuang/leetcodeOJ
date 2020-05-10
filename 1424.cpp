class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        vector<pair<int, int>> index;
        int rows = nums.size();
        if (rows == 0) return res;
        int cols = nums[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                index.push_back(pair<int, int>(i, j));
            }
        }
        sort(index.begin(), index.end(), cmp);
        for (int i = 0; i < index.size(); i++) {
            res.push_back(nums[index[i].first][index[i].second]);
        }
        return res;
    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first + a.second == b.first + b.second) return a.second < b.second;
        return a.first + a.second < b.first + b.second;
    }
};
