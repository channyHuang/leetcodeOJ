class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int glen = g.size(), slen = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int spos = 0;
        int res = 0;
        for (int i = 0; i < glen; i++) {
            while (spos < slen && s[spos] < g[i]) spos++;
            if (spos == slen) return res;
            res++;
            spos++;
        }        
        return res;
    }   
};
