class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int len = parents.size();
        vector<vector<int>> children(len, vector<int>());
        vector<int> count(len, 0);
        vector<long long> value(len, 1);
        for (int i = 1; i < len; ++i) {
          children[parents[i]].push_back(i);
          count[parents[i]]++;
        }
        queue<int> qu;
        for (int i = 0; i < len; ++i) {
          if (count[i] == 0) qu.push(i);
        }
        while (!qu.empty()) {
          int cur = qu.front();
          qu.pop();
          if (cur == 0) continue;
          value[parents[cur]] += value[cur];
          count[parents[cur]]--;
          if (count[parents[cur]] == 0) {
            qu.push(parents[cur]);
          }
        }

        vector<long long> score(len, 0);
        if (children[0].size() <= 1) score[0] = value[children[0][0]];
        else score[0] = value[children[0][0]] * value[children[0][1]];
        long long maxn = score[0];
        int res = 1;
        for (int i = 1; i < len; ++i) {
          score[i] = (value[0] - value[i]);
          for (int j = 0; j < children[i].size(); j++) {
            score[i] *= (value[children[i][j]]);
          }
          if (maxn < score[i]) {
            maxn = score[i];
            res = 1;
          } else if (maxn == score[i]) {
            res++;
          }
        }
        return res;
    }
};
