class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int len = aliceArrows.size(); // 12
        vector<int> res(len, 0);
        maxbit = 0;
        maxn = 0;
        maxArrows = 0;
        search(numArrows, aliceArrows, 0, 0, 0, 0);
        int lastIdx = 0;
        for (int i = 0; i < len; ++i) {
          if (maxbit & (1 << i)) {
            res[i] = aliceArrows[i] + 1;
            lastIdx = i;
          }
        }
        if (maxArrows < numArrows) res[lastIdx] += (numArrows - maxArrows);
        return res;
    }

    void search(int numArrows, vector<int>& aliceArrows, int curbit, int curpos, int curscore, int curArrows) {
      if (curpos >= 12) {
        if (curscore > maxn) {
          maxn = curscore;
          maxbit = curbit;
          maxArrows = curArrows;
        }
        return;
      }
      search(numArrows, aliceArrows, curbit, curpos + 1, curscore, curArrows);
      if (curArrows + aliceArrows[curpos] + 1 <= numArrows) {
        search(numArrows, aliceArrows, curbit | (1 << curpos), curpos + 1, curscore + curpos, curArrows + aliceArrows[curpos] + 1);
      }
    }

private:
    int maxn = 0;
    int maxbit = 0;
    int maxArrows = 0;
};
