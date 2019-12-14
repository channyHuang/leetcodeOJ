class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int left[3] = {0};
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) left[0]++;
            else if (bills[i] == 10) {
                left[0]--;
                if (left[0] < 0) return false;
                left[1]++;
            } else {
                if (left[0] == 0) return false;
                left[0]--;
                if (left[1] > 0) left[1]--;
                else left[0] -= 2;
                if (left[0] < 0) return false;
            }
        }
        return true;
    }
};
