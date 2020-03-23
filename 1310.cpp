class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int len = arr.size();
        vector<int> res;
        int sum[len] = {0};
        sum[0] = arr[0];
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i - 1] ^ arr[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) res.push_back(sum[queries[i][1]]);
            else res.push_back(sum[queries[i][1]] ^ sum[queries[i][0] - 1]);
        }
        return res;
    }
};
