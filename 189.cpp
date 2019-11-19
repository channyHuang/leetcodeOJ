class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k >= len) k %= len;
        if (k == 0) return;
        
        int factor = maxFactor(k, len);

        for (int i = 0; i < factor; i++) {
            rotateOne(nums, i, k, len);
        }
    }

    void rotateOne(vector<int> &nums, int stPos, int k, int len) {
        int prePos = stPos;
        int nextPos = (stPos + k) % len;
        int preNum = nums[stPos];
        while (nextPos != stPos) {
            int tmp = nums[nextPos];
            nums[nextPos] = preNum;
            preNum = tmp;

            prePos = nextPos;
            nextPos = (nextPos + k) % len;
        }
        nums[stPos] = preNum;
    }

    int maxFactor(int k, int len) {
        int tmp;
        while (k != 0) {
            tmp = len % k;
            len = k;
            k = tmp;
        }
        return len;
    }
};
