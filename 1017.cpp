class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        int k = -2;
        vector<int> res;
        while (N) {
            int r = (N % k + abs(k)) % abs(k);
            res.push_back(r);
            N -= r;
            N /= k;
        }
        //reverse(res.begin(), res.end());
        string str;
        for (int i = res.size() - 1; i >= 0; i--) {
            str += to_string(res[i]);
        }
        return str;
    }
};
