class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int len = nums.size();
        if (len <= 3) return false;
        target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 4 != 0) return false;
        target /= 4;
        int edges[4][20];
        int sum[4];
        int pos[4];
        memset(sum, 0, sizeof(sum));
        memset(pos, 0, sizeof(pos));
        edges[0][0] = nums[0]; 
        sum[0] = nums[0];
        pos[0] = 1;
        search(nums, 1, edges, sum, pos);
        return res;    
    }

    void search(vector<int>& nums, int curPos, int edges[4][20], int sum[4], int pos[4]) {
        if (curPos >= nums.size()) {
            res = true;
            return;
        }
        if (res) return;
        for (int j = 0; j < 4; j++) {
            if (sum[j] + nums[curPos] <= target) {
                edges[j][pos[j]++] = nums[curPos];
                sum[j] += nums[curPos];
                search(nums, curPos + 1, edges, sum, pos);
                pos[j]--;
                sum[j] -= nums[curPos];
            }
        }
    }

private:
    bool res;
    int target;
};
