class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        //map insert auto sort
        int len = nums.size();
        map<int, int> maps;
        vector<string> res;
        res.resize(len);
        for (int i = 0; i < len; i++) {
            maps.insert(make_pair(nums[i], i));
        }
        int pos = len;
        for (map<int, int>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            if (pos == 1) res[itr->second] = "Gold Medal";
            else if (pos == 2) res[itr->second] = "Silver Medal";
            else if (pos == 3) res[itr->second] = "Bronze Medal";
            else res[itr->second] = to_string(pos);
            pos--;
        }
        return res;
    }
};
