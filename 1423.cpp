class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int stPos = k - 1;
        int stSum = 0;
        int endPos = len - 1;      
        for (int i = 0; i < k; i++) stSum += cardPoints[i];
        int res = stSum;
        while (stPos >= 0) {
            stSum -= cardPoints[stPos--];
            stSum += cardPoints[endPos--];
            res = max(res, stSum);
        }
        return res;
    }
};
