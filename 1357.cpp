class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        count = n;
        discnt = discount;
        for (int i = 0; i < products.size(); i++) {
            maps.insert(pair<int, int>(products[i], prices[i]));
        }
        cnt = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double totalPrice = 0;
        map<int, int>::iterator itr;
        for (int i = 0; i < product.size(); i++) {
            itr = maps.find(product[i]);
            totalPrice += (itr->second * amount[i]);
        }
        cnt++;
        if (cnt == count) {
            totalPrice -= (discnt * totalPrice) / 100.0;
            cnt = 0;
        }
        return totalPrice;
    }

private:
    int count;
    int cnt;
    int discnt;
    map<int, int> maps;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
