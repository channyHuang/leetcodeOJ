class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int len = answerKey.length();
        if (len <= k) return len;
        // len > k
        vector<int> nums(1, 1);
        int pos = 0;
        int res = 0;
        int stcount = 0;
        for (int i = 1; i < len; ++i) {
            if (answerKey[i] == answerKey[i - 1]) {
                nums[pos]++;
            }
            else {
                res = std::max(res, nums[pos]);
                if ((pos & 1) == 0) stcount += nums[pos];
                nums.push_back(1);
                pos++;
            }
        }
        if (pos <= 0) return len;
        if ((pos & 1) == 0) stcount += nums[pos];
        if (stcount <= k || len - stcount <= k) return len;
        res = std::max(res, nums[pos]);

        int countst = nums[0], countse = 0;
        int stpos = 0, endpos = 1;
        while (endpos <= pos) {
            if ((endpos & 1) == (stpos & 1)) {
                countst += nums[endpos];
                endpos++;
            } else if (countse + nums[endpos] <= k) {
                countse += nums[endpos];
                endpos++;
            } else {
                res = std::max(res, countst + k);

                countst -= nums[stpos];
                stpos++;
                int tmp = countse;
                countse = countst;
                countst = tmp;
                while (countse > k) {
                    countst -= nums[stpos];
                    stpos++;
                    int tmp = countse;
                    countse = countst;
                    countst = tmp;
                }
            }

        }
        res = std::max(res, countst + k);
        return std::min(res, len);
    }
};
