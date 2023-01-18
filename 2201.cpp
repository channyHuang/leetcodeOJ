class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> mesh(n, vector<int>(n, 0));
        int dlen = dig.size();
        for (int i = 0; i < dlen; ++i) {
          mesh[dig[i][0]][dig[i][1]] = 1;
        }
        int alen = artifacts.size();
        int res = 0;
        for (int i = 0; i < alen; ++i) {
          // artifacts 
          bool flag = true;
          for (int x = artifacts[i][0]; x <= artifacts[i][2]; ++x) {
            for (int y = artifacts[i][1]; y <= artifacts[i][3]; ++y) {
              if (mesh[x][y] == 0) {
                flag = false;
                break;
              }
            }
            if (!flag) break;
          }
          if (flag) res++;
        }
        return res;
    }
};
