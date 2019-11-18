class FizzBuzz {
private:
    int n;

public:
    mutex muFizz, muBuzz, muFB, muNum;

    FizzBuzz(int n) {
        this->n = n;
        muFizz.lock();
        muBuzz.lock();
        muNum.lock();
    }
    //3
    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 1; i <= n; i++) {     
            if (i % 3 == 0 && i % 5 != 0) {
                muFizz.lock();
                printFizz();
                muFB.unlock();
            }
        }
    }
    //5
    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 1; i <= n; i++) {
            if (i % 3 != 0 && i % 5 == 0) {
                muBuzz.lock();
                printBuzz();
                muFB.unlock();
            }
        }
    }
    //2
    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i <= n; i++) {
            muFB.lock();
            if (i % 3 == 0 && i % 5 == 0) {            
                printFizzBuzz();
                muFB.unlock();
            } else if (i % 3 == 0) {
                muFizz.unlock();
            } else if (i % 5 == 0) {
                muBuzz.unlock();
            } else {
                muNum.unlock();
            }
        }
    }
    //4
    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) { 
            if (i % 3 != 0 && i % 5 != 0) {
                muNum.lock();
                printNumber(i);
                muFB.unlock();
            }
        }
    }
};
