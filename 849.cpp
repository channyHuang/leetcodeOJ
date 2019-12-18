class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        int i = 0, res = 0;
        while (i < len && seats[i] == 0) {
            res++;
            i++;
        }
        int count = 0;
        while (len > 0 && seats[len - 1] == 0) {
            count++;
            len--;
        }
        res = max(res, count);
        for (; i < len; i++) {
            if (seats[i]) {
                if (count) res = max(res, count / 2 + count % 2);
                count = 0;
            } else count++;
        }
        return res;
    }
};
