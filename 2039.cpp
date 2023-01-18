// path双向。。。
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int plen = patience.size();
        int elen = edges.size();
        vector<unordered_set<int>> children(plen, unordered_set<int>());
        vector<int> path(plen, -1);
        for (int i = 0; i < elen; ++i) {
          children[edges[i][0]].insert(edges[i][1]);
          children[edges[i][1]].insert(edges[i][0]);
        }
        path[0] = 0;
        queue<int> qu;
        qu.push(0);
        while (!qu.empty()) {
          auto cur = qu.front();
          qu.pop();
          int next = path[cur] + 1;
          for (auto itr = children[cur].begin(); itr != children[cur].end(); itr++) {
            if (path[*itr] >= 0) continue;
            path[*itr] = next;
            qu.push(*itr);
          }
        }

        int last = 0;
        for (int i = 1; i < plen; ++i) {
          
          int backtime = (path[i] << 1);
          last = std::max(last, backtime);
          if (patience[i] >= backtime) {
            continue;
          }
          int left = backtime % patience[i];
          int time = backtime - (left == 0 ? patience[i] : left) + backtime;
          last = std::max(last, time);
        }
        return last + 1;
    }
};
