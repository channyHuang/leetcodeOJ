class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.clear();
        history.push_back(homepage);
        pos = 0;
        count = 1;
    }
    
    void visit(string url) {
        if (history.size() <= pos + 1) {
            history.push_back(url);
            ++pos;
        } else {
            history[++pos] = url;
        }
        count = pos + 1;
    }
    
    string back(int steps) {
        pos -= steps;
        if (pos < 0) pos = 0;
        return history[pos];
    }
    
    string forward(int steps) {
        pos += steps;
        if (pos > count - 1) pos = count - 1;
        return history[pos];
    }
private:
    vector<string> history;
    int count; //页面数
    int pos; //当前下标
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
