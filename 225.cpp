class MyStack {
public:
    queue<int> qu[2];
    int curPos;

    /** Initialize your data structure here. */
    MyStack() {
        while (!qu[0].empty()) qu[0].pop();
        while (!qu[1].empty()) qu[1].pop();
        curPos = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        qu[curPos].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (qu[curPos].size()) {
            if (qu[curPos].size() == 1) {
                int res = qu[curPos].front();
                qu[curPos].pop();
                curPos = 1 - curPos;
                return res;
            }
            qu[1 - curPos].push(qu[curPos].front());
            qu[curPos].pop();
        }
        return 0;
    }
    
    /** Get the top element. */
    int top() {
        while (qu[curPos].size()) {
            if (qu[curPos].size() == 1) {
                int res = qu[curPos].front();
                qu[curPos].pop();
                curPos = 1 - curPos;
                qu[curPos].push(res);
                return res;
            }
            qu[1 - curPos].push(qu[curPos].front());
            qu[curPos].pop();
        }
        return 0;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qu[curPos].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
