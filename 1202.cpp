class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        len = s.length();
        parents.resize(len, 0);
        for (int i = 0; i < len; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < pairs.size(); i++) {
            int p1 = findParents(pairs[i][0]);
            parents[pairs[i][0]] = p1;
            int p2 = findParents(pairs[i][1]);
            parents[pairs[i][1]] = p1;
            if (p1 == p2) continue;
            parents[p2] = p1;
        }
        unordered_map<int, vector<int>> maps;
        for (int i = 0; i < len; i++) {
            int p = findParents(i);
            maps[p].push_back(i);
        }
        string res = s;
        for (unordered_map<int, vector<int>>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second.size() <= 1) continue;
            vector<char> vec;
            for (int i = 0; i < itr->second.size(); i++) {
                vec.push_back(s[itr->second[i]]);
            }
            sort(vec.begin(), vec.end());
            for (int i = 0; i < itr->second.size(); i++) {
                res[itr->second[i]] = vec[i];
            }
        }
        return res;
    }

    int findParents(int idx) {
        while (idx != parents[idx]) idx = parents[idx];
        return idx;
    }

private:
    vector<int> parents;
    int len;
};

//TLE
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        len = s.length();
        parents.resize(len, 0);
        for (int i = 0; i < len; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < pairs.size(); i++) {
            int p1 = findParents(pairs[i][0]);
            int p2 = findParents(pairs[i][1]);
            if (p1 == p2) continue;
            parents[p2] = p1;
        }
        unordered_map<int, vector<char>> maps;
        unordered_map<int, int> index;
        for (int i = 0; i < len; i++) {
            int p = findParents(i);
            parents[i] = p;
            maps[p].push_back(s[i]);
        }
        for (unordered_map<int, vector<char>>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            sort(itr->second.begin(), itr->second.end());
            index[itr->first] = 0;
        }
        for (int i = 0; i < len; i++) {
            int p = parents[i];
            s[i] = maps[p][index[p]];
            index[p]++;
        }
        return s;
    }

    int findParents(int idx) {
        while (idx != parents[idx]) idx = parents[idx];
        return idx;
    }

private:
    vector<int> parents;
    int len;
};
