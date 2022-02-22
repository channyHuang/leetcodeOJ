class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum & 1) return res;
        // finalSum >= 2
        int cur = 2;
        while (finalSum >= cur) {
            res.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }
        res[res.size() - 1] += finalSum;
        return res;
    }
};
