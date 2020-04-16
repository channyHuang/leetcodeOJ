class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < k) return 0;
        int res = 0;
        vector<int> index;
        index.push_back(-1);
        int count = 1;
        for (int i = 0; i < len; i++) {
            if ((nums[i] & 1) == 1) {
                index.push_back(i);
                count++;
                if (count > k + 1) {
                    res += (index[count - 1] - index[count - 1 - 1]) * (index[count - 1 - k] - index[count - 1 - k - 1]);
                }
            }
        }
        index.push_back(len);
        count++;
        if (count > k + 1) {
            res += (index[count - 1] - index[count - 1 - 1]) * (index[count - 1 - k] - index[count - 1 - k - 1]);
        }

        return res;
    }
};
