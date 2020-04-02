class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res;
        res.resize(5);
        int len = count.size();
        if (len <= 0) return res;
        int stPos = 0;
        int endPos = len - 1;
        while (count[stPos] <= 0) stPos++;
        while (count[endPos] <= 0) endPos--;
        res[0] = stPos;
        res[1] = endPos;
        int maxCount = stPos;
        int left = 0;
        int right = 0;
        double totalSum = 0;
        int totalCount = 0;
        while (stPos <= endPos) {
            if (stPos == endPos) {
                if (count[maxCount] < count[stPos]) maxCount = stPos;
                totalSum += (count[stPos] * stPos);
                totalCount += count[stPos];
                break;
            }
            if (left <= right) {
                left += count[stPos];
                totalSum += (count[stPos] * stPos);
                totalCount += count[stPos];
                if (count[maxCount] < count[stPos]) maxCount = stPos;
                stPos++;
            }
            if (right < left) {
                right += count[endPos];
                totalSum += (count[endPos] * endPos);
                totalCount += count[endPos];
                if (count[maxCount] < count[endPos]) maxCount = endPos;
                endPos--;
            }
        }
        res[2] = totalSum / totalCount;
        res[4] = maxCount;
        if (totalCount & 1 == 1) {
            int midPos = totalCount / 2;
            int cnt = 0;
            int i;
            for (i = 0; i < len; i++) {
                cnt += count[i];
                if (cnt > midPos) break;
            }
            res[3] =  i;
        } else {
            int midPos = totalCount / 2;
            int cnt = 0;
            int i;
            for (i = 0; i < len; i++) {
                cnt += count[i];
                if (cnt >= midPos) break;
            }
            res[3] =  i;
            if (cnt == midPos) {
                i++;
                while (count[i] == 0) i--;
            }
            res[3] += i;
            res[3] /= 2.0;
        }
        return res;
    }
};
