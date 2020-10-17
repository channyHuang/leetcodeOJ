class Solution {
public:  
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> res;
        int len = arrival.size();
        vector<int> count(k, 0);
        int maxn = -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
        set<int> free;
        for (int i = 0; i < k; i++) free.insert(i);
        for (int i = 0; i < len; i++) {          
            while (!qu.empty() && qu.top().first <= arrival[i]) {
                free.insert(qu.top().second);
                qu.pop();
            }
            if (free.empty()) continue;
            int idx = i % k;
            auto itr = free.lower_bound(idx);
            if (itr == free.end()) {
                idx = *(free.begin());
            } else {
                idx = *itr;
            }
            free.erase(idx);            
            qu.push(pair<int, int>(arrival[i] + load[i], idx));           
            count[idx]++;
            if (maxn < count[idx]) {
                maxn = count[idx];
                res.clear();
                res.push_back(idx);
            } else if (maxn == count[idx]) {
                res.push_back(idx);
            }           
        }
        return res;
    }

};
