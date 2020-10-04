class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        len = edges.size();
        for (int i = 0; i <= len; i++) {
            parents.push_back(i);
        }
        vector<vector<int>> conflicts;
        int circle = -1;
        for (int i = 0; i < len; i++) {
            int stPos = edges[i][0];
            int endPos = edges[i][1];
            int paSt = findParents(stPos);
            int paEnd = findParents(endPos);
            
            
            //circle, double parent
            if (paEnd == paSt && parents[endPos] != endPos) {
                return edges[i];
            }
            //circle
            if (paEnd == paSt) {
                circle = i;
                if (!conflicts.empty()) {
                    return conflicts[0];
                }
            } else if (parents[endPos] != endPos) { //double parent
                if (circle != -1) return {parents[endPos], endPos};
                conflicts.push_back({parents[endPos], endPos});
                conflicts.push_back(edges[i]);                
            } else {
                parents[endPos] = stPos;
            }
        }
        return conflicts.empty() ? edges[circle] : conflicts.back();
    }

    int findParents(int idx) {
        while (idx != parents[idx]) idx = parents[idx];
        return idx;
    }

private:
    vector<int> parents;
    int len;
};
