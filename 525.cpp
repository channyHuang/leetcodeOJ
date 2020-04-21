class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        if (sum == len - sum) return len;
        if (sum == 0 || sum == len) return 0;
        map<int, int> maps;
        map<int, int>::iterator itr;
        int res = 2;
        int count = 0;
        for (int i = 0; i < len; i++) {
            count += (nums[i] ? 1 : -1);
            if (count == 0) {
                res = max(res, i + 1);
            } else {
                itr = maps.find(count);
                if (itr == maps.end()) {
                    maps.insert(pair<int, int>(count, i));
                } else {
                    res = max(res, i - itr->second);
                }
            }
        }
        return res;
    }
};
