class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int count[32] = {0};
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) count[j]++;
            }
        }
        for (int i = 0; i < 32; i++) {
            res = res + count[i] * (len - count[i]);
        }
        return res;
    }
};



/*TLE
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int tmp = nums[i] ^ nums[j];
                while (tmp) {
                    tmp &= (tmp - 1);
                    res++;
                }
            }
        }
        return res;
    }
};
*/
