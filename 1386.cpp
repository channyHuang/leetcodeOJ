class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), cmp);
        int seats = 0;
        int res = 0;
        int len = reservedSeats.size();
        int cntRow = 0;
        int count = 0;
        int lastRow = reservedSeats[0][0];
        //30: 11 110, 480: 11 1100 000, 120: 1111 000
        for (int i = 0; i <= len; i++) {
            if (i == len || reservedSeats[i][0] != lastRow) {
                cntRow++;
                if ((seats & 30) == 0) {
                    if ((seats & 480) == 0) {
                        res += 2;
                    } else res += 1;
                } else if ((seats & 480) == 0) {
                    res++;
                } else if ((seats & 120) == 0) {
                    res++;
                }
                if (i == len) break;
                seats = 0;
                lastRow = reservedSeats[i][0];
            }
            seats |= ( 1 << (reservedSeats[i][1] - 1));
        }
        return res + (n - cntRow) * 2;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};
