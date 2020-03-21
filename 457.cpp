class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return false;
        int used[len] = {0};
        bool positive = true;
        int level = 0;
        for (int i = 0; i < len; i++) {
            if (used[i]) continue;
            level++;
            used[i] = level;
            positive = (nums[i] > 0);
            int pos = i + nums[i];
            while (pos < 0 || pos >= len) pos = (pos + len) % len;
            if (pos == i) continue;
            while (1) {
                if ((positive && nums[pos] < 0) || (!positive && nums[pos] > 0)) break;
                if ((used[pos] > 0) && (used[pos] != level)) break;
                if (used[pos] == level) return true;
                used[pos] = level;
                int lastPos = pos;
                pos = lastPos + nums[lastPos]; 
                while (pos < 0 || pos >= len) pos = (pos + len) % len;       
                if (pos == lastPos) break;
            }
        }
        return false;
    }
};
