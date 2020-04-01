class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //if (equations.size() == 1) return true;
        int parent[26];
        for (int i = 0; i < 26; i++) {
            parent[i] = -1;
        }
        int stPos = 0, endPos = equations.size() - 1;
        while (stPos <= endPos) {
            while (stPos <= endPos && equations[stPos][1] == '=') stPos++;
            while (stPos <= endPos && equations[endPos][1] == '!') endPos--;
            if (stPos >= endPos) break;
            string tmp = equations[stPos];
            equations[stPos] = equations[endPos];
            equations[endPos] = tmp;
            stPos++;
            endPos--;
        }
        for (int i = 0; i < stPos; i++) {
            int pa = findParent(parent, equations[i][0] - 'a');
            int pb = findParent(parent, equations[i][3] - 'a');
            //if (i == 2) return findParent(parent, 'j' - 'a') == -1;
            if (pa == -1) {
                if (pb == -1) {
                    parent[equations[i][0] - 'a'] = equations[i][0] - 'a';
                    parent[equations[i][3] - 'a'] = equations[i][0] - 'a';
                } else {
                    parent[equations[i][0] - 'a'] = pb;
                }
            } else {
                if (pb == -1) parent[equations[i][3] - 'a'] = pa;
                else parent[pb] = pa;
            }
            
        }
        for (int i = stPos; i < equations.size(); i++) {
            if (equations[i][0] == equations[i][3]) return false;
            int pa = findParent(parent, equations[i][0] - 'a');
            int pb = findParent(parent, equations[i][3] - 'a');
            
            if (pa == -1 && pb == -1) {
                parent[equations[i][0] - 'a'] = equations[i][0] - 'a';
                parent[equations[i][3] - 'a'] = equations[i][3] - 'a';
            } else if (pa == -1) {
                parent[equations[i][0] - 'a'] = equations[i][0] - 'a';
            } else if (pb == -1) {
                parent[equations[i][3] - 'a'] = equations[i][3] - 'a';
            } else {
                if (pa == pb) return false;
            }
        }

        return true;
    }

    int findParent(int parent[], int idx) {
        if (parent[idx] == -1) return -1;
        while (parent[idx] != idx) idx = parent[idx];
        return idx;
    }
};
