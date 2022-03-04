class StockPrice {
public:
    struct Node {
        int timestamp;
        int price;
        Node* left;
        Node* right;
        Node* parent;
        Node(int _time, int _price) : timestamp(_time), price(_price), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    StockPrice() {
        minprice = (1 << 30);
        maxprice = 0;
    }
    
    void update(int timestamp, int price) {
        auto itr = time2price.find(timestamp);
        if (itr == time2price.end()) { // new timestamp
            time2price[timestamp] = price;
            price2count[price]++;

            if (minprice > price) minprice = price;
            if (maxprice < price) maxprice = price;
            if (curtime < timestamp) curtime = timestamp;
        } else { // update timestamp
            auto pitr = price2count.find(itr->second);
            int research = 0; // 1 search min price, 2 search max price, 3 search both
            if (pitr->second == 1) {
                price2count.erase(pitr);

                if (itr->second == minprice) research |= 1;
                if (itr->second == maxprice) research |= 2;
            } else {
                pitr->second--;
            }

            time2price[timestamp] = price;
            price2count[price]++;

            if (research != 0) {
                auto nitr = price2count.begin();
                if (research == 1 || research == 3) {
                    minprice = nitr->first;
                } 
                if (research == 2 || research == 3) {
                    while (nitr != price2count.end()) {
                        maxprice = nitr->first;
                        nitr++;
                    }
                } 
            }
            if (minprice > price) minprice = price;
            if (maxprice < price) maxprice = price;
        }
    }
    
    int current() {
        return time2price[curtime];
    }
    
    int maximum() {
        return maxprice;
    }
    
    int minimum() {
        return minprice;
    }

private:
    map<int, int> time2price;
    map<int, int> price2count;
    int minprice, maxprice;
    int curtime = 0;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

