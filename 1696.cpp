class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        priority_queue<pair<int, int>> qu;
        qu.push(pair<int, int>(nums[0], 0));
        vector<int> score(len, INT_MIN);
        score[0] = nums[0];

        for (int i = 1; i < len; i++) {
            pair<int, int> cur;
            while (!qu.empty()) {
                cur = qu.top();
                if (cur.second < i - k) {
                    qu.pop();
                } else {
                    break;
                }
            }
            score[i] = max(score[i], cur.first + nums[i]);
            qu.push(pair<int, int>(score[i], i));
        }
        return score[len - 1];
    }
};
