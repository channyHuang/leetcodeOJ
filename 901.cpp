class StockSpanner {
public:
    StockSpanner() {
        count = 0;
    }
    
    int next(int price) {
        int res = 1;
        int pos = count - 1;
        while (pos >= 0) {
            if (prices[pos] <= price) {
                res += cnt[pos];
                pos -= cnt[pos];
            } else break;
        }
        prices.push_back(price);
        count++;
        cnt.push_back(res);
        return res;
    }

private:
    vector<int> prices;
    vector<int> cnt;
    int count;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
