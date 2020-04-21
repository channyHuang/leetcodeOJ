class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int, int>> pairs;
        int len = values.size();
        if (len <= 0) return 0;
        for (int i = 0; i < len; i++) pairs.push_back(pair<int, int>(values[i], labels[i]));
        sort(pairs.begin(), pairs.end(), cmp);
        map<int, int> maps;
        map<int, int>::iterator itr;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            itr = maps.find(pairs[i].second);
            if (itr != maps.end() && itr->second >= use_limit) continue;
            if (itr == maps.end()) maps.insert(pair<int, int>(pairs[i].second, 1));
            else itr->second++;
            count++;
            sum += pairs[i].first;
            if (count >= num_wanted) break;
        }
        return sum;
    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return (a.first > b.first);
    }
};