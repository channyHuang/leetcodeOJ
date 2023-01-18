class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(), arr.end());
        long long result = 1;
        vector<long long> res(len, 1);
        unordered_map<int, int> maps;
        for (int i = 0; i < len; ++i) {
            maps[arr[i]] = i;
        }
        for (int i = 1; i < len; ++i) {
            int maxfactor = std::sqrt(arr[i]);
            int pos = 0; 
            while (pos < len && arr[pos] <= maxfactor) {
                if (arr[i] % arr[pos] != 0) {
                    pos++;
                    continue;
                }
                auto itr = maps.find(arr[i] / arr[pos]);
                if (itr == maps.end()) {
                    pos++;
                    continue;
                }
                if (arr[itr->second] == arr[pos]) {
                    res[i] += (res[pos] * res[pos]);
                } else {
                    res[i] += (res[pos] * res[itr->second] * 2);
                }
                res[i] %= maxn;
                pos++;
            }
            result += res[i];
            result %= maxn;
        }
        //for (int i = 0; i < len; ++i) {
        //    cout << res[i] << " ";
        //}
        //cout << endl;
        return result;
    }

private:
    int maxn = 1000000007;
};
