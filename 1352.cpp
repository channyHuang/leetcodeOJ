class ProductOfNumbers {
public:
    ProductOfNumbers() {
        count = 0;
        vec.clear();
        mulnum.clear();
    }
    
    void add(int num) {
        vec.push_back(num);
        if (count == 0) mulnum.push_back(num);
        else mulnum.push_back(num * mulnum[count - 1]);
        count++;
    }
    
    int getProduct(int k) {
        int res = 1;
        if (k == count) return mulnum[count - 1];
        if (mulnum[count - k - 1] == 0) {
            for (int i = count - 1; i >= count - k; i--) {
                res *= vec[i];
            }
            return res;
        } else return mulnum[count - 1] / mulnum[count - k - 1]; 
    }

private:
    int count;
    vector<int> vec;
    vector<int> mulnum;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
