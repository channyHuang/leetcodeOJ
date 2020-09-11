class Solution {
public:
    class Project
    {
    public:
        int profit;
        int capital;
        bool valid;
        Project(int _profit = 0, int _capital = 0) {
            profit = _profit;
            capital = _capital;
            valid = true;
        }
    };

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int res = W;
        int len = Profits.size();
        std::vector<Project> projects;
        for (int i = 0; i < len; i++) {
            //if (Profits[i] <= Capital[i]) continue;
            projects.push_back(Project(Profits[i], Capital[i]));
        }
        std::sort(projects.begin(), projects.end(), cmp);
        len = projects.size();
        int pos = 0;
        while (pos < len && (projects[pos].capital > W || projects[pos].valid == false)) pos++;
        if (pos >= len) return res;
        //w increase
        while (k--) {
            W += (projects[pos].profit - projects[pos].capital);
            res += projects[pos].profit;
            projects[pos].valid = false;
            cout << res << endl;

            pos = 0;
            while (pos < len && (projects[pos].capital > W || projects[pos].valid == false)) pos++;
            if (pos >= len) return res;
        }

        return res;
    }

    static bool cmp(const Project& a, const Project& b) {
        if (a.profit - a.capital == b.profit - b.capital) {
            return a.profit > b.profit;
        }
        return a.profit - a.capital > b.profit - b.capital;
    }
};
