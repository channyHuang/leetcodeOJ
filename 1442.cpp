class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size();
        map<int, vector<int>> maps;
        map<int, vector<int>>::iterator itr;
        int res = 0;
        int sum = 0;
        {
            vector<int> sub(1, -1);
            maps.insert(pair<int, vector<int>>(0, sub));
        }
        for (int i = 0; i < len; i++) {
            sum ^= arr[i];
            itr = maps.find(sum);
            if (itr == maps.end()) {
                vector<int> sub(1, i);
                maps.insert(pair<int, vector<int>>(sum, sub));
            } else {
                for (int j = 0; j < itr->second.size(); j++) {
                    res += max(0, i - itr->second[j] - 1);
                }
                itr->second.push_back(i);
            }
        }
        return res;
    }
};
