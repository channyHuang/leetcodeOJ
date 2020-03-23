class CustomStack {
public:
    int num[1005];
    int maxn;
    int pos;

    CustomStack(int maxSize) {
        maxn = maxSize;
        pos = 0;
    }
    
    void push(int x) {
        if (pos >= maxn) return;
        num[pos++] = x;
    }
    
    int pop() {
        if (pos <= 0) return -1;
        pos--;
        return num[pos];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k; i++) num[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
