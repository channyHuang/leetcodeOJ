class FooBar {
private:
    int n;

public:
    mutex mfoo, mbar;

    FooBar(int n) {
        this->n = n;
        mbar.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            mfoo.lock();
        	printFoo();
            mbar.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            mbar.lock();
        	printBar();
            mfoo.unlock();
        }
    }
};
