class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        if (k >= 10 || k <= 0) return res;
        int num[10];
        for (int i = 1; i <= 9; i++) {
            num[0] = i;
            search(num, k, n, 1, i);
        }
        return res;
    }

    void search(int num[], int k, int n, int curPos, int curSum) {
        if (curSum > n || curPos > k) return;
        if (curSum == n || curPos == k) {
            if (curSum != n) return;
            if (curPos != k) return;
            vector<int> subres;
            for (int i = 0; i < k; i++) subres.push_back(num[i]);
            res.push_back(subres);
            return;
        }
        for (int i = num[curPos - 1] + 1; i <= 9; i++) {
            num[curPos] = i;
            search(num, k, n, curPos + 1, curSum + i);
        }
    }
};
