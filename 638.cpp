class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int lenp = price.size();
        int lens = special.size();
        for (int i = 0; i < lenp; i++) {
            res += (price[i] * needs[i]);
        }
        vector<int> curGoods(lenp, 0);
        search(price, special, needs, curGoods, 0, 0);
        return res;
    }

    void search(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, vector<int>& curGoods, int nextPos, int value) {
        int lenp = price.size();
        int left = 0;
        for (int i = 0; i < lenp; i++) {
            left += (price[i] * (needs[i] - curGoods[i]));
        }
        if (left <= 0) {
            res = min(res, value);
            return;
        }
        res = min(res, value + left);
        if (nextPos >= special.size()) return;
        vector<int> lastGoods = curGoods;
        search(price, special, needs, curGoods, nextPos + 1, value);
        int count = 0;
        while (1) {
            bool flag = true;
            for (int i = 0; i < lenp; i++) {
                curGoods[i] += special[nextPos][i];
                if (curGoods[i] > needs[i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            count++;
            search(price, special, needs, curGoods, nextPos + 1, value + count * special[nextPos][lenp]);
        }
        curGoods = lastGoods;
    }

private:
    int res;
};
