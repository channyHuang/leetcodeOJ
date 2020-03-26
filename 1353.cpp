class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int len = events.size();
        if (len <= 1) return len;
        sort(events.begin(), events.end(), cmpst);
        int curDay = events[0][0];
        vector<vector<int>> waitQueue;
        int res = 0; 
        int pos = 1;
        waitQueue.push_back(events[0]);
        while (pos < len && events[pos][0] == curDay) waitQueue.push_back(events[pos++]);
        sort(waitQueue.begin(), waitQueue.end(), cmpend);
        while (waitQueue.size()) {
            waitQueue.erase(waitQueue.begin());
            res++;
            while (!waitQueue.empty() && waitQueue[0][1] == curDay) waitQueue.erase(waitQueue.begin());

            if (waitQueue.empty()) {
                if (pos >= len) break;
                waitQueue.push_back(events[pos]);
                curDay = events[pos][0];
                pos++;
                while (pos < len && events[pos][0] == curDay) waitQueue.push_back(events[pos++]);
                sort(waitQueue.begin(), waitQueue.end(), cmpend);
            } else {
                curDay++;
                if (pos >= len) continue;
                while (pos < len && events[pos][0] == curDay) waitQueue.push_back(events[pos++]);
                sort(waitQueue.begin(), waitQueue.end(), cmpend);
            }
        }
        return res;
    }

    static bool cmpst(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] <= b[1];
        return a[0] < b[0];
    }
    static bool cmpend(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] <= b[0];
        return a[1] < b[1];
    }
};
