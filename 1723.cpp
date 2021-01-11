class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        len = jobs.size();
        vector<int> workers(len, 0);
        sort(jobs.begin(), jobs.end(), greater());
        int i = 0;
        while (i < len) {
            maxn += jobs[i];
            i += k;
        }
        workers[0] = jobs[0];
        dfs(jobs, workers, jobs[0], 1, k);
        return maxn;
    } 
    
    void dfs(vector<int>& jobs, vector<int>& workers, int tmpmax, int pos, int k) {
        if (pos >= len) {            
            maxn = min(maxn, tmpmax);
            return;
        }
        for (int i = 0; i < k; i++) {           
            if (workers[i] + jobs[pos] > maxn) continue;
            workers[i] += jobs[pos];
            dfs(jobs, workers, (tmpmax > workers[i] ? tmpmax : workers[i]), pos + 1, k);
            workers[i] -= jobs[pos]; 
            if (workers[i] == 0) break;         
        }
    }
    
private:
    int maxn = 0;
    int len;
};
