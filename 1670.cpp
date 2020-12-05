class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        //flen == slen || flen == slen - 1
        flen = 0;
        slen = 0;
    }
    
    void pushFront(int val) {
        first.push_front(val);
        flen++;
        if (flen > slen) {
            int mid = first.back();
            first.pop_back();
            flen--;
            second.push_front(mid);
            slen++;
        }
    }
    
    void pushMiddle(int val) {
        if (flen == slen) {
            second.push_front(val);
            slen++;
        } else {
            first.push_back(val);
            flen++;
        }
    }
    
    void pushBack(int val) {
        second.push_back(val);
        slen++;
        if (flen < slen - 1) {
            int mid = second.front();
            second.pop_front();
            slen--;
            first.push_back(mid);
            flen++;
        }
    }
    
    int popFront() {
        int res = -1;
        if (slen == 0) return res;
        if (slen == 1 && flen == 0) {
            res = second.front();
            second.pop_front();
            slen--;
            return res;
        }
        res = first.front();
        first.pop_front();
        flen--;
        if (flen < slen - 1) {
            int mid = second.front();
            second.pop_front();
            slen--;
            first.push_back(mid);
            flen++;
        }
        return res;
    }
    
    int popMiddle() {
        int res = -1;
        if (slen == 0) return res;
        if (flen == slen) {
            res = first.back();
            first.pop_back();
            flen--;
        } else {
            res = second.front();
            second.pop_front();
            slen--;
        }
        return res;
    }
    
    int popBack() {
        int res = -1;
        if (slen == 0) return res;
        res = second.back();
        second.pop_back();
        slen--;
        if (flen > slen) {
            int mid = first.back();
            first.pop_back();
            flen--;
            second.push_front(mid);
            slen++;
        }
        return res;
    }

private:
    deque<int> first;
    deque<int> second;
    int flen, slen;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
