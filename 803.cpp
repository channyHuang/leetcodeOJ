class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        rows = grid.size();
        cols = grid[0].size();
        len = hits.size();
        int step = 2;
        vector<int> res(len, 0);
        vector<vector<int>> count = grid;
        for (int i = len - 1; i >= 0; i--) {
            count[hits[i][0]][hits[i][1]] = 0;
        }
        vector<int> cnt(2, 0);
        vector<bool> stable(2, false);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (count[i][j] != 1) continue;
                bool bStable = false;
                cnt.push_back(bfs(count, step, i, j, bStable));
                step++;
                stable.push_back(bStable);
            }
        }

        /*for (int i = 2; i < cnt.size(); i++) {
            cout << cnt[i] << " " << stable[i] << endl;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << count[i][j] << " ";
            }
            cout << endl;
        }*/
        
        vector<int> parent(step, -1);
        for (int i = len - 1; i >= 0; i--) {
            if (grid[hits[i][0]][hits[i][1]] == 0) continue;
            
            int bStable = (hits[i][0] == 0 ? true : false);
            vector<int> par;
            if (hits[i][0] > 0 && count[hits[i][0] - 1][hits[i][1]] != 0) {
                par.push_back(findParent(parent, count[hits[i][0] - 1][hits[i][1]]));
                bStable |= stable[par[par.size() - 1]];
            }
            if (hits[i][0] < rows - 1 && count[hits[i][0] + 1][hits[i][1]] != 0) {
                par.push_back(findParent(parent, count[hits[i][0] + 1][hits[i][1]]));
                bStable |= stable[par[par.size() - 1]];
            }
            if (hits[i][1] > 0 && count[hits[i][0]][hits[i][1] - 1] != 0) {
                par.push_back(findParent(parent, count[hits[i][0]][hits[i][1] - 1]));
                bStable |= stable[par[par.size() - 1]];
            }
            if (hits[i][1] < cols - 1 && count[hits[i][0]][hits[i][1] + 1] != 0) {
                par.push_back(findParent(parent, count[hits[i][0]][hits[i][1] + 1]));
                bStable |= stable[par[par.size() - 1]];
            }

            /*cout << "i = " << i << endl;
            for (int x = 0; x < par.size(); x++) {
                cout << par[x] << " ";
            }
            cout << endl;*/

            int plen = par.size();
            if (plen == 0) {
                count[hits[i][0]][hits[i][1]] = step;
                cnt.push_back(1);
                if (hits[i][0] == 0) stable.push_back(true);
                else stable.push_back(false);
                parent.push_back(-1);
                step++;
                continue;
            }

            if (!stable[par[0]] && bStable) {
                res[i] += cnt[par[0]];
                stable[par[0]] = bStable;
            }
            
            for (int j = 1; j < plen; j++) {
                if (par[j] == par[0]) continue;
                par[j] = findParent(parent, par[j]);
                if (par[j] == par[0]) continue;
                parent[par[j]] = par[0];
                
                if (!stable[par[j]] && bStable) {
                    res[i] += cnt[par[j]];
                    stable[par[j]] = bStable;
                } else if (!bStable) {
                    cnt[par[0]] += cnt[par[j]];
                }
            }
            if (!bStable) {
                cnt[par[0]] += 1;
            }
            count[hits[i][0]][hits[i][1]] = par[0];
        }
        return res;
    }

    int findParent(vector<int>& parent, int idx) {
        while (parent[idx] != -1) {
            idx = parent[idx];
        }
        return idx;
    }

    int bfs(vector<vector<int>>& count, int step, int r, int c, bool& bStable) {
        queue<pair<int, int>> qu;
        qu.push(pair<int, int>(r, c));
        if (r == 0) bStable = true;
        else bStable = false;
        count[r][c] = step;
        int res = 0;
        while (!qu.empty()) {
            pair<int, int> cur = qu.front();
            qu.pop();
            res++;
            if (cur.first < rows - 1 && count[cur.first + 1][cur.second] == 1) {
                count[cur.first + 1][cur.second] = step;
                qu.push(pair<int, int>(cur.first + 1, cur.second));
            }
            if (cur.first > 0 && count[cur.first - 1][cur.second] == 1) {
                count[cur.first - 1][cur.second] = step;
                qu.push(pair<int, int>(cur.first - 1, cur.second));
            }
            if (cur.second < cols - 1 && count[cur.first][cur.second + 1] == 1) {
                count[cur.first][cur.second + 1] = step;
                qu.push(pair<int, int>(cur.first, cur.second + 1));
            }
            if (cur.second > 0 && count[cur.first][cur.second - 1] == 1) {
                count[cur.first][cur.second - 1] = step;
                qu.push(pair<int, int>(cur.first, cur.second - 1));
            }
        }

        return res;
    }

private:
    int rows;
    int cols;
    int len;
};
