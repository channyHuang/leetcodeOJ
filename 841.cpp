class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool used[rooms.size()] = {0};
        queue<int> qu;
        qu.push(0);
        while (!qu.empty()) {
            if (used[qu.front()]) {
                qu.pop();
                continue;
            } 
            used[qu.front()] = true;
            for (int i = 0; i < rooms[qu.front()].size(); i++) {
                if (used[rooms[qu.front()][i]]) continue;
                qu.push(rooms[qu.front()][i]);
            }
            qu.pop();
        }
        for (int i = 0; i < rooms.size(); i++) {
            if (!used[i]) return false;
        }
        return true;
    }
};
