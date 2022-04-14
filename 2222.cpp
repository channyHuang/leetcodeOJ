class Solution {
public:
    long long numberOfWays(string s) {
        vector<int> count(1, 1);
        int slen = s.length();
        int pos = 0;
        for (int i = 1; i < slen; ++i) {
            if (s[i] == s[i - 1]) count[pos]++;
            else {
                count.push_back(1);
                pos++;
            }
        }
        if (pos <= 1) return 0;
        vector<vector<long long>> sum(pos + 1, vector<long long>(3, 0)); //from count[i], select j buildings
        sum[pos][0] = count[pos];
        sum[pos - 1][0] = count[pos - 1];
        sum[pos - 1][1] = count[pos - 1] * count[pos];
        for (int i = pos - 2; i >= 0; --i) {
            sum[i][0] = count[i] + sum[i + 2][0];
            sum[i][1] = count[i] * sum[i + 1][0] + sum[i + 2][1];
            sum[i][2] = count[i] * sum[i + 1][1] + sum[i + 2][2]; 
        }
        return sum[0][2] + sum[1][2];
    }
};
