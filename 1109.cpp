class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int len = bookings.size();
        vector<int> res(n, 0);
        for (int i = 0; i < len; i++) {
            res[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] != n) res[bookings[i][1]] -= bookings[i][2];
        }
        for (int i = 1; i < n; i++) {
            res[i] += res[i - 1];
        }
        return res;
    }
};
