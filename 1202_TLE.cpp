class Solution {
public:
    class Node {
    public:
        set<int> index;
        vector<char> c;
        int pos;
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.length();
        int parents[len];
        Node nodes[len];
        bool used[len];
        for (int i = 0; i < len; i++) {
            parents[i] = i;
            nodes[i].index.insert(i);
            used[i] = false;
        }
        for (int i = 0; i < pairs.size(); i++) {
            int p1 = findParents(parents, len, pairs[i][0]);
            int p2 = findParents(parents, len, pairs[i][1]);
            if (p1 == p2) continue;
            parents[p2] = p1;            
            for (set<int>::iterator itr = nodes[p2].index.begin(); itr != nodes[p2].index.end(); itr++) {
                nodes[p1].index.insert(*itr);
            }
            used[p2] = true;
        }
        string res = s;
        for (int i = 0; i < len; i++) {
            if (used[i]) continue;
            if (nodes[parents[i]].c.size() <= 0) {
                for (set<int>::iterator itr = nodes[i].index.begin(); itr != nodes[i].index.end(); itr++) {
                    nodes[parents[i]].c.push_back(s[*itr]);
                }
                sort(nodes[parents[i]].c.begin(), nodes[parents[i]].c.end());
                nodes[parents[i]].pos = 0;
            }
            res[i] = nodes[parents[i]].c[nodes[parents[i]].pos++];
        }
        return res;
    }

    int findParents(int parents[], int len, int idx) {
        while (idx != parents[idx]) idx = parents[idx];
        return idx;
    }
};
