class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        vector<int> res = nums;
        sort(res.begin(), res.end()); 
        sort(res.begin(), res.begin() + len / 2 + (len & 1), greater());
        sort(res.begin() + len / 2 + (len & 1), res.end(), greater());
        int pos = 0;
        for (int i = 0; i < len; i++) {
            nums[pos] = res[i];
            pos += 2;
            if (pos >= len) pos = 1;
        }
    }
};
