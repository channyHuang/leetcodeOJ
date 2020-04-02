class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int len = people.size();
        if (len <= 1) return len;
        bool used[len];
        memset(used, 0, sizeof(used));
        sort(people.begin(), people.end());
        int stPos = 0;
        int endPos = len - 1;
        int res = 0;
        while (stPos <= endPos) {
            if (stPos == endPos) {
                res++;
                return res;
            }
            if (people[stPos] + people[endPos] <= limit) {
                res++;
                stPos++;
                endPos--;
            }
            else {
                res++;
                endPos--;
            }
        }
        return res;
    }
};
