class MyCircularQueue {
public:
    vector<int> res;
    int stPos;
    int endPos;
    int count;
    int maxn;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        res.clear();
        res.resize(k);
        stPos = 0;
        endPos = 0;
        count = 0;
        maxn = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (maxn == count) return false;
        if (count == 0) {
            res[stPos] = value;
        } else {
            endPos = (endPos + 1) % maxn;
            res[endPos] = value;
        }
        count++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (count == 0) return false;
        count--;
        if (count == 0) {
            stPos = 0;
            endPos = 0;
        } else {
            stPos = (stPos + 1) % maxn;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (count == 0) return -1;
        return res[stPos];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (count == 0) return -1;
        return res[endPos];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return !count;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (count == maxn);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
