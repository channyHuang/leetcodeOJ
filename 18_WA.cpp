class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len <= 3) return res;
        sort(nums.begin(), nums.end());
        map<int, vector<vector<int>>> maps;
        map<int, vector<vector<int>>>::iterator itr;
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int tmp = nums[i] + nums[j];
                itr = maps.find(tmp);
                if (itr == maps.end()) {
                    vector<int> sub;
                    sub.push_back(nums[i]);
                    sub.push_back(nums[j]);
                    vector<vector<int>> subres;
                    subres.push_back(sub);
                    maps.insert(pair<int, vector<vector<int>>>(tmp, subres));
                } else {
                    vector<int> sub;
                    sub.push_back(nums[i]);
                    sub.push_back(nums[j]);
                    itr->second.push_back(sub);
                }
            }
        }
        if ((target & 1) == 0) {
            itr = maps.find(target >> 1);
            if (itr != maps.end()) {
                vector<vector<int>> tmp = itr->second;
                for (int i = 0; i < tmp.size(); i++) {
                    for (int j = i + 1; j < tmp.size(); j++) {
                        if (itr->second[i][1] > itr->second[j][0]) continue;
                        vector<int> sub;
                        sub.push_back(tmp[i][0]);
                        sub.push_back(tmp[i][1]);
                        sub.push_back(tmp[j][0]);
                        sub.push_back(tmp[j][1]);
                        res.push_back(sub);
                    }
                }
            }
        }
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (target - itr->first <= itr->first) break;
            map<int, vector<vector<int>>>::iterator itr2 = maps.find(target - itr->first);
            if (itr2 == maps.end()) continue; 
            for (int i = 0; i < itr->second.size(); i++) {
                for (int j = 0; j < itr2->second.size(); j++ ) {
                    if (itr->second[i][1] > itr2->second[j][0]) continue;
                    vector<int> sub;
                    sub.push_back(itr->second[i][0]);
                    sub.push_back(itr->second[i][1]);
                    sub.push_back(itr2->second[j][0]);
                    sub.push_back(itr2->second[j][1]);
                    res.push_back(sub);
                }
            }
        }
        return res;
    }
};
