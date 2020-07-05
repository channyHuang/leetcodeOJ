class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        sets.clear();
        count = 0;
    }
    
    void addNum(int num) {
        sets.insert(num);
        if (count == 0) {
            itr = sets.begin();
            count++;
            return;
        }
        if (count & 1) { //odd before add num
            if (num < *itr) itr--;
        } else {
            if (num >= *itr) itr++;
        }
        count++;
    }
    
    double findMedian() {
        if (count == 0) return 0;
        if (count & 1) return *itr;
        multiset<int>::iterator tmp = itr;
        tmp++;
        return (*tmp + *itr) / 2.0;
    }

private:
    multiset<int> sets;
    multiset<int>::iterator itr;
    int count;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
