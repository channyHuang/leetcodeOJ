class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        map<int, vector<pair<int, int>>> maps;
        map<int, vector<pair<int, int>>>::iterator itr;
        bool used[n];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < flights.size(); i++) {
            itr = maps.find(flights[i][0]);
            if (itr == maps.end()) {
                vector<pair<int, int>> vec;
                pair<int, int> curPair(flights[i][1], flights[i][2]);
                vec.push_back(curPair);
                maps.insert(pair<int, vector<pair<int, int>>>(flights[i][0], vec));
            } else {
                itr->second.push_back(pair<int, int>(flights[i][1], flights[i][2]));
            }
        }
        res = -1;
        vector<vector<int>> heap;
        {
            vector<int> sub;
            sub.push_back(src);
            sub.push_back(0); //k
            sub.push_back(0); //cost;
            heap.push_back(sub);
        }
        used[src] = true;
        while (heap.size() > 0) {
            vector<int> cur = heap[0];
            heap.erase(heap.begin());
            if (cur[0] == dst) {
                if (res == -1) res = cur[2];
                else res = min(res, cur[2]);
                continue;
            }
            if (cur[1] > K || (res != -1 && cur[2] >= res)) continue;
            used[cur[0]] = true;
            itr = maps.find(cur[0]);
            if (itr == maps.end()) continue;
            for (int i = 0; i < itr->second.size(); i++) {
                if (used[itr->second[i].first]) continue;
                vector<int> sub;
                sub.push_back(itr->second[i].first);
                sub.push_back(cur[1] + 1); //k
                sub.push_back(cur[2] + itr->second[i].second); //cost;
                heap.push_back(sub);
                int idx = heap.size() - 1;
                int pidx = (idx - 1) / 2;
                while(pidx >= 0) {
                    if (heap[idx][2] < heap[pidx][2]) {
                        vector<int> tmp = heap[idx];
                        heap[idx] = heap[pidx];
                        heap[pidx] = tmp;
                        idx = pidx;
                        pidx = (idx - 1) / 2;
                    } else break;
                }
            }
        }
        return res;
    }

private:
    int res;
};
/*TLE
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        map<int, vector<pair<int, int>>> maps;
        map<int, vector<pair<int, int>>>::iterator itr;
        for (int i = 0; i < flights.size(); i++) {
            itr = maps.find(flights[i][0]);
            if (itr == maps.end()) {
                vector<pair<int, int>> vec;
                pair<int, int> curPair(flights[i][1], flights[i][2]);
                vec.push_back(curPair);
                maps.insert(pair<int, vector<pair<int, int>>>(flights[i][0], vec));
            } else {
                itr->second.push_back(pair<int, int>(flights[i][1], flights[i][2]));
            }
        }
        res = -1;
        queue<vector<int>> qu;
        {           
            vector<int> sub;
            sub.push_back(src);
            sub.push_back(0); //k
            sub.push_back(0); //cost
            qu.push(sub);
        }
        while (!qu.empty()) {
            vector<int> cur = qu.front();
            qu.pop();
            if (cur[0] == dst) {
                if (res == -1) res = cur[2];
                else res = min(res, cur[2]);
                continue;
            }
            if (cur[1] > K) continue;
            itr = maps.find(cur[0]);
            if (itr == maps.end()) continue;
            for (int i = 0; i < itr->second.size(); i++) {
                vector<int> sub;
                sub.push_back(itr->second[i].first);
                sub.push_back(cur[1] + 1);
                sub.push_back(cur[2] + itr->second[i].second);
                qu.push(sub);
            }
        }
        return res;
    }

private:
    int res;
};
*/
