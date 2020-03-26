class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();     
        if (len <= 0) return res;
        maxn.clear();
        int maxcount = 0;
        for (int i = 0; i < len; i++) {
            int tmp = target / candidates[i];
            maxn.push_back(tmp);
            maxcount += tmp;
        }
        vector<int> sub;
        sub.resize(maxcount);
        search(candidates, target, sub, 0, 0, 0);
        return res;
    }

    void search(vector<int>& candidates, int& target, vector<int>& sub, int curPos, int pos, int curSum) {
        if (curSum > target) return;
        if (curSum == target) {
            vector<int> subres;
            for (int i = 0; i < pos; i++) {
                subres.push_back(sub[i]);
            }
            res.push_back(subres);
            return;
        }
        if (curPos >= candidates.size()) return;
        for (int j = 0; j <= maxn[curPos]; j++) {
            int sum = candidates[curPos] * j;
            if (curSum + sum > target) break;
            for (int k = 0; k < j; k++)
                sub[pos + k] = candidates[curPos];
            search(candidates, target, sub, curPos + 1, pos + j, curSum + sum);
        }
        
    }

private:
    vector<vector<int>> res;
    vector<int> maxn;
};
