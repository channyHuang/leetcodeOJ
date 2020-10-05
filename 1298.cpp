class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {      
        queue<int> qu;
        for (int i = 0; i < initialBoxes.size(); i++) {
            boxes[initialBoxes[i]] = status[initialBoxes[i]];
            if (status[initialBoxes[i]] == 1) {
                qu.push(initialBoxes[i]);
            }
        }
        while (!qu.empty()) {
            int curIdx = qu.front();
            qu.pop();
            if (status[curIdx] != 1) continue;
            res += candies[curIdx];
            status[curIdx] = 2;
            for (int i = 0; i < keys[curIdx].size(); i++) {
                if (status[keys[curIdx][i]] == 0) {
                    status[keys[curIdx][i]] = 1;
                    if (boxes.find(keys[curIdx][i]) != boxes.end()) {
                        qu.push(keys[curIdx][i]);
                    }
                }
            }
            for (int i = 0; i < containedBoxes[curIdx].size(); i++) {
                boxes[containedBoxes[curIdx][i]] = status[containedBoxes[curIdx][i]];
                if (status[containedBoxes[curIdx][i]] == 1) {
                    qu.push(containedBoxes[curIdx][i]);
                }
            }
        }
        return res;
    }

private:
    int res;
    unordered_map<int, int> boxes;
};
