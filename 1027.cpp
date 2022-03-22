class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len;
        int res = 2;
        unordered_map<int, vector<int>> maps;
        for (int i = 0; i < len; ++i) {
            maps[nums[i]].push_back(i);
            res = std::max(res, (int)maps[nums[i]].size());
        }
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums[j] != nums[i]) {
                    int lastIdx = j;
                    int diff = nums[j] - nums[i];
                    int curlen = 2;
                    int nextIdx = findUpper(maps[nums[lastIdx] + diff], lastIdx);
                    while (nextIdx != -1) {
                        if (curlen + len - lastIdx - 1 <= res) break;

                        curlen++;
                        lastIdx = nextIdx;
                        nextIdx = findUpper(maps[nums[lastIdx] + diff], lastIdx);
                    }

                    res = std::max(res, curlen);
                }
            }
        }
        return res;
    }

    int findUpper(vector<int> &index, int tarIdx) {
        int len = index.size();
        if (len <= 0) return -1;
        if (tarIdx >= index[len - 1]) return -1;
        int minn = 0, maxn = len - 1;
        int res = -1;
        while (minn <= maxn) {
            int midn = (minn + maxn) / 2;
            if (index[midn] <= tarIdx) minn = midn + 1;
            else {
                res = index[midn];
                maxn = midn - 1;
            }
        }
        return res;
    }
};
