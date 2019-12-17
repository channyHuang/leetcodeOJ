class MyQueue {
public:
    stack<int> st[2];
    int curPos;
    /** Initialize your data structure here. */
    MyQueue() {
        while (!st[0].empty()) st[0].pop();
        while (!st[1].empty()) st[1].pop();
        curPos = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st[curPos].push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (st[curPos].size()) {
            if (st[curPos].size() == 1) {
                int res = st[curPos].top();
                st[curPos].pop();
                while (!st[1 - curPos].empty()) {
                    st[curPos].push(st[1 - curPos].top());
                    st[1 - curPos].pop();
                }
                return res;
            }
            st[1 - curPos].push(st[curPos].top());
            st[curPos].pop();
        }
        return 0;
    }
    
    /** Get the front element. */
    int peek() {
        while (st[curPos].size()) {
            if (st[curPos].size() == 1) {
                int res = st[curPos].top();
                st[1 - curPos].push(res);
                st[curPos].pop();
                while (!st[1 - curPos].empty()) {
                    st[curPos].push(st[1 - curPos].top());
                    st[1 - curPos].pop();
                }
                return res;
            }
            st[1 - curPos].push(st[curPos].top());
            st[curPos].pop();
        }
        return 0;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st[curPos].empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
