class Solution {public:    vector<int> maxScoreIndices(vector<int>& nums) {        int len = nums.size();        vector<int> sum(len, 0);        sum[0] = 1 - nums[0];        for (int i = 1; i < len; ++i) {            sum[i] = sum[i - 1] + (nums[i] == 0 ? 1 : 0);        }        vector<int> res;        int total0 = sum[len - 1], total1 = (len - total0);        int maxScore = std::max(total0, len - total0);        if (total0 >= total1) {            res.push_back(len);        }        if (total1 >= total0) {            res.push_back(0);        }        for (int i = 0; i < len - 1; ++i) {            int curScore = sum[i] + (len - i - 1 - (total0 - sum[i]));            if (curScore < maxScore) continue;            if (curScore == maxScore) {                res.push_back(i + 1);            } else {                maxScore = curScore;                res.clear();                res.push_back(i + 1);            }        }        return res;    }};