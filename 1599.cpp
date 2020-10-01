class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int len = customers.size();
        int round = 0;
        int turn = 0;
        int money = 0;
        //while (turn < len && customers[turn] <= 0) turn++;
        while (turn < len) {
            money += min(4, customers[turn]) * boardingCost;
            money -= runningCost;
            round++;
            //cout << money << endl;
            if (maxn < money) {
                maxn = money;
                res = round;
            }
            customers[turn] -= 4;
            if (turn == len - 1 && customers[turn] <= 0) break;
            if (customers[turn] > 0 && (turn < len - 1)) {
                customers[turn + 1] += customers[turn];
            }
            if (turn < len - 1) turn++;
            
            //while (turn < len && customers[turn] <= 0) turn++;
        }
        return res;
    }

private:
    int res = -1;
    int maxn = 0;
};
