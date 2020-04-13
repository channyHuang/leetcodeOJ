class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        vector<int> res = nums;
        sort(res.begin(), res.end()); 
        int pos1 = 0;     
        int pos2 = len / 2;
        int pos = 0;
        for (int i = 0; i < pos2; i++) {
            nums[pos++] = res[i];
            if (pos >= len) break;
            nums[pos++] = res[pos2 + i];
        }
    }
};
