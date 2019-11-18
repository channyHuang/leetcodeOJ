class H2O {
private:
    int countH;

public:
    mutex muH, muO;

    H2O() {
        muO.lock();
        countH = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        muH.lock();
        releaseHydrogen();
        this->countH++;
        if (this->countH == 2) {
            this->countH = 0;
            muO.unlock();
        } else {
            muH.unlock();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        muO.lock();
        releaseOxygen();
        muH.unlock();
    }
};
