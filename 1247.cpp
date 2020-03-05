class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int countx[2] = {0}, county[2] = {0};
        if (s1.length() != s2.length()) return -1;     
        int diff = 0;                                                                          
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[i]) continue;
            diff++;
            if (s1[i] == 'x') countx[0]++;
        }
        county[0] = diff - countx[0];


        if (diff & 1) return -1;

        return countx[0] / 2 + county[0] / 2 + (countx[0] & 1) * 2;
    }
};
