class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int len = arr.size();
        int sum = arr[0];
        multimap<int, int> maps;
        int pos = 0;
        if (sum == target) {
            maps.insert(make_pair(1, 0));
        }
        for (int i = 1; i < len; i++) {
            sum += arr[i];
            if (sum > target) {
                while (sum > target) {
                    sum -= arr[pos++];
                }
            }
            if (sum == target) {
                maps.insert(make_pair(i - pos + 1, pos));
            }
        }
        int res = INT_MAX;
        for (multimap<int, int>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            multimap<int, int>::iterator nitr = itr;
            for (nitr++; nitr != maps.end(); nitr++) {
                if (itr->first + nitr->first >= res) break;
                if (itr->second < nitr->second && itr->second + itr->first > nitr->second) continue;
                if (itr->second > nitr->second && itr->second < nitr->second + nitr->first) continue;
                res = min(res, itr->first + nitr->first);
                break;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
