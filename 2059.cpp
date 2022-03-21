class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int len = nums.size();
        if (start == goal) return 0;
        queue<pair<int, int>> qu;
        unordered_set<int> sets;

        qu.push(make_pair(start, 0));
        sets.insert(start);
        while (!qu.empty()) {
            auto cur = qu.front();
            qu.pop();

            for (int i = 0; i < len; ++i) {
                // add
                int tmp = cur.first + nums[i];
                if (tmp == goal) return cur.second + 1;
                if (valid(tmp) && sets.find(tmp) == sets.end()) {
                    sets.insert(tmp);
                    qu.push(make_pair(tmp, cur.second + 1));
                }
                // minus
                tmp = cur.first - nums[i];
                if (tmp == goal) return cur.second + 1;
                if (valid(tmp) && sets.find(tmp) == sets.end()) {
                    sets.insert(tmp);
                    qu.push(make_pair(tmp, cur.second + 1));
                }
                // or
                tmp = (cur.first ^ nums[i]);
                if (tmp == goal) return cur.second + 1;
                if (valid(tmp) && sets.find(tmp) == sets.end()) {
                    sets.insert(tmp);
                    qu.push(make_pair(tmp, cur.second + 1));
                }
            }
        }
        return -1;
    }

    bool valid(int n) {
        return (n >= 0 && n <= 1000);
    }
};
