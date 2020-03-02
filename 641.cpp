class MyCircularDeque {
public:
    vector<int> res;
    int stPos;
    int endPos;
    int count;
    int maxn;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        res.clear();
        res.resize(k);
        stPos = 0;
        endPos = 0;
        count = 0;
        maxn = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (count == maxn) return false;
        if (count == 0) {
            res[stPos] = value;
        } else {
            stPos = (stPos - 1 + maxn) % maxn;
            res[stPos] = value; 
        }
        count++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (count == maxn) return false;
        if (count == 0) {
            res[stPos] = value;
        } else {
            endPos = (endPos + 1) % maxn;
            res[endPos] = value;
        }
        count++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (count == 0) return false;
        stPos = (stPos + 1) % maxn;
        count--;
        if (count == 0) {
            stPos = 0;
            endPos = 0;
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (count == 0) return false;
        endPos = (endPos - 1 + maxn) % maxn;
        count--;
        if (count == 0) {
            stPos = 0;
            endPos = 0;
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (count == 0) return -1;
        return res[stPos]; 
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (count == 0) return -1;
        return res[endPos]; 
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return !count;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (count == maxn);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
