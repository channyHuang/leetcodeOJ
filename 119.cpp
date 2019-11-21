class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        //if (rowIndex == 0) return res;
        res.push_back(1);
        if (rowIndex == 0) return res;

        res.push_back(rowIndex);
        if (rowIndex == 1) return res;
        //C(n, m) = n!/(m!(n-m)!)
        //C(n, m + 1) = C(n, m)*(n - m)/(m + 1)
        for (int i = 2; i <= rowIndex; i++) {
            long long last = res[res.size() - 1];
            long long next = last * (rowIndex - i + 1) / i;

            res.push_back(next);
        }
        return res;
    }


};
