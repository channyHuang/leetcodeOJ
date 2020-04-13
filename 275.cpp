class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        sort(citations.begin(), citations.end());
        int stPos = 0, endPos = len - 1;
        int minn = 0;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            int tmp = min(len - midPos, citations[midPos]);
            if (tmp > minn) {
                minn = tmp;
            }
            if (citations[midPos] > tmp) {
                endPos = midPos - 1;
            }
            else stPos = midPos + 1;
        }
        return minn;

    }
};
