class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combine(int n, int k) {       
        vector<int> sub;
        sub.resize(k);
        search(sub, n, k, 1, 0);
        return res;
    }

    void search(vector<int>& sub, int n, int k, int pos, int curCount) {
        if (curCount >= k) {
            vector<int> subres = sub;
            res.push_back(subres);
            return;
        }
        for (int i = pos; i <= n; i++) {         
            sub[curCount] = i;
            search(sub, n, k, i + 1, curCount + 1);
        }
    }
};
