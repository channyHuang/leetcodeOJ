class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int len = prerequisites.size();
        vector<vector<int>> maps;
        int incount[numCourses];
        bool used[numCourses] = {0};
        for (int i = 0; i < numCourses; i++) {
            incount[i] = false;
            vector<int> submaps;
            maps.push_back(submaps);
        }
        for (int i = 0; i < len; i++) {
            maps[prerequisites[i][1]].push_back(prerequisites[i][0]);
            incount[prerequisites[i][0]]++;
        }

        vector<int> learned;    
        int pos = 0;
        while (1) {
            bool haschange = false;
            for (int i = 0; i < numCourses; i++) {
                if (incount[i] != 0 || used[i]) continue;
                haschange = true;
                learned.push_back(i);
                used[i] = true;
                pos = learned.size() - 1;

                while (pos < learned.size()) {
                    for (int j = 0; j < maps[learned[pos]].size(); j++) {
                        //if (used[maps[learned[pos]][j]]) return false;
                        //used[maps[learned[pos]][j]] = true;
                        incount[maps[learned[pos]][j]]--;
                        //learned.push_back(maps[learned[pos]][j]);
                    }
                    pos++;
                }
            }
            if (!haschange) break;
        }
        for (int i = 0; i < numCourses; i++) {
            if (!used[i]) return false;
        }
        return true;
    }
};
