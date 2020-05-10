class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        if (len <= 2) return 0;
        //up
        vector<int> vec = nums;
        for (int i = 1; i < len; i++) {
            if (i & 1) {
                if (vec[i] > vec[i - 1]) continue;
                res += vec[i - 1] - vec[i] + 1;
                vec[i - 1] = vec[i] - 1;
            } else {
                if (vec[i] < vec[i - 1]) continue;
                res += vec[i] - vec[i - 1] + 1;
                vec[i] = vec[i - 1] - 1;
            }
        }
        //down
        vec = nums;
        int tmp = 0;
        for (int i = 1; i < len; i++) {
            if (i & 1) {
                if (vec[i] < vec[i - 1]) continue;
                tmp += vec[i] - vec[i - 1] + 1;
                vec[i] = vec[i - 1] - 1;
            } else {
                if (vec[i] > vec[i - 1]) continue;
                tmp += vec[i - 1] - vec[i] + 1;
                vec[i - 1] = vec[i] - 1;
            }
        }
        return min(res, tmp);
    }
};
