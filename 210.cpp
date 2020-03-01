class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        while (1) {
            bool haschange = false;
            for (int i = 0; i < numCourses; i++) {
                if (incount[i] != 0 || used[i]) continue;
                haschange = true;
                learned.push_back(i);
                used[i] = true;

                for (int j = 0; j < maps[i].size(); j++) {
                    incount[maps[i][j]]--;
                }
            }
            if (!haschange) break;
        }
        vector<int> res;
        if (learned.size() < numCourses) return res;
        return learned;
    }
};


