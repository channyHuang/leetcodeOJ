class ZeroEvenOdd {
private:
    int n;

public:
    mutex muZero, muEven, muOdd;

    ZeroEvenOdd(int n) {
        this->n = n;
        muEven.lock();
        muOdd.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            muZero.lock();
            printNumber(0);
            if (i & 1) muOdd.unlock();
            else muEven.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            muEven.lock();
            printNumber(i);
            muZero.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+= 2) {
            muOdd.lock();
            printNumber(i);   
            muZero.unlock();
        }
    }
};
