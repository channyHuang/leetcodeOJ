class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        maps.clear();
        res.clear();
        phash.clear();

        for (int i = 0; i < req_skills.size(); i++) {
            maps[req_skills[i]] = (1 << i);
        }
        target = pow(2, req_skills.size()) - 1;
        
        for (int i = 0; i < people.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < people[i].size(); j++) {
                unordered_map<string, int>::iterator itr = maps.find(people[i][j]);
                if (itr != maps.end()) {
                    tmp |= itr->second;
                }
            }
            if (tmp == 0) continue;
            bool keep = true;
            for (unordered_map<int, int>::iterator itr = phash.begin(); itr != phash.end(); ) {
                if ((itr->first & tmp) == itr->first) {
                    itr = phash.erase(itr);                   
                } else if ((itr->first & tmp) == tmp) {
                    keep = false;
                    break;
                } else {
                    itr++;
                }
            }
            if (keep) phash[tmp] = i;
        }
        plen = phash.size();

        vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= target; i++) {
            if (dp[i] == INT_MAX) continue;
            for (unordered_map<int, int>::iterator itr = phash.begin(); itr != phash.end(); itr++) {
                if ((i | itr->first) <= i) continue;
                dp[i | itr->first] = min(dp[i | itr->first], dp[i] + 1);
            }
        }

        rlen = dp[target];      
        vector<pair<int, int>> path(rlen, pair<int, int>(0, 0));
        unordered_map<int, int>::iterator itr = phash.begin();
        //cout << "plen = " << plen << ", rlen = " << rlen << endl;
        search(itr, 0, path, 0);
        return res;
    }

    void search(unordered_map<int, int>::iterator itr, int nPeople, vector<pair<int, int>>& path, int stPos) {       
        if (rlen - nPeople > plen - stPos) return;
        if (res.size() >= rlen) return;
        if (nPeople >= rlen) {            
            int tmp = 0;
            for (int i = 0; i < rlen; i++) {
                tmp |= path[i].first;
            }            
            if ((tmp & target) == target) {
                for (int i = 0; i < rlen; i++) {
                    res.push_back(path[i].second);
                }
            }
            return;
        }
        //cout << "npeople = " << nPeople << ", stPos = " << stPos << endl;
        
        int nextPos = stPos;
        for (unordered_map<int, int>::iterator nitr = itr; nitr != phash.end(); nitr++) {
            path[nPeople] = pair<int, int>(nitr->first, nitr->second);
            nextPos++;
            unordered_map<int, int>::iterator nnitr = nitr;
            nnitr++;
            search(nnitr, nPeople + 1, path, nextPos);
        }
    }

private:
    unordered_map<string, int> maps;
    
    vector<int> res;
    int rlen;
    int plen;
    unordered_map<int, int> phash;
    int minn;
    int target;
};
