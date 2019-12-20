class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> sets;
        for (int i = 0; i < obstacles.size(); i++) {
            sets.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
        //N, E, S, W
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int pos = 0;
        int x = 0, y = 0;
        int nextx = 0, nexty = 0;
        int res = 0;
        for (int i = 0; i < commands.size(); i++) {
            switch(commands[i]) {
            case -2:
            pos = (pos + 4 - 1) % 4;
            break;
            case -1:
            pos = (pos + 1) % 4;
            break;
            default:
            for (int j = 1; j <= commands[i]; j++) {
                nextx = x + dx[pos];
                nexty = y + dy[pos];
                if (sets.find(make_pair(nextx, nexty)) != sets.end()) break;
                x = nextx;
                y = nexty;
            }
            res = max(res, x * x + y * y);
            break;
            }
        }
        return res;
    }
};
