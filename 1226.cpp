class DiningPhilosophers {
public:
    mutex fork[5];
    int left;
    mutex cirLeft;
    DiningPhilosophers() {
        this->left = 0;
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        //if pick left leads to dead lock, forkCir will be in locked status
        cirLeft.lock();
        //pick left
		fork[philosopher].lock();
        left++;
        pickLeftFork();
        if (left < 4) cirLeft.unlock();

        //pick right
        fork[(philosopher + 1) % 5].lock();
        pickRightFork();

        eat();

        putLeftFork();
        fork[philosopher].unlock();
        left--;
        cirLeft.unlock();

        putRightFork();
        fork[(philosopher + 1) % 5].unlock();
    }
};
