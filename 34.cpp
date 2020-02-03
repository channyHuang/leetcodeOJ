class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        return searchRange(nums, target, 0, len - 1);
    }

    vector<int> searchRange(vector<int>& nums, int target, int stPos, int endPos) {
        vector <int> res;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (nums[midPos] == target) {
                res.push_back(findStart(nums, target, stPos, midPos));
                res.push_back(findEnd(nums, target, midPos, endPos));
                return res;
            }
            if (nums[midPos] > target) return searchRange(nums, target, stPos, midPos - 1);
            return searchRange(nums, target, midPos + 1, endPos);
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }

    int findStart(vector<int>& nums, int target, int stPos, int endPos) {
        int res = endPos;
        int i = 1;
        while (1) {
            if (res == stPos) return stPos;
            while (res - i < stPos) {
                i >>= 1;
                if (i == 0) return res;
            }
            if (nums[res - i] != target) {
                if (i == 1) return res;
                i >>= 1;
            } else {
                res = res - i;
                i <<= 1;
            }
        }
        return res;
    }

    int findEnd(vector<int>& nums, int target, int stPos, int endPos) {
        int res = stPos;
        int i = 1;
        while (1) {
            if (res == endPos) return endPos;
            while (res + i > endPos) {
                i >>= 1;
                if (i == 0) return res;
            }
            if (nums[res + i] != target) {
                if (i == 1) return res;
                i >>= 1;
            } else {
                res = res + i;
                i <<= 1;
            }
        }
        return res;
    }
};