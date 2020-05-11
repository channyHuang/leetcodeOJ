class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();
        if (len == 1) return (senate[0] == 'R' ? "Radiant" : "Dire");
        vector<bool> used(len, false); 
        while (1) {
            for (int i = 0; i < len; i++) {
                if (used[i]) continue;
                if (senate[i] == 'R') {
                    int stD = (i + 1) % len;
                    while (stD != i) {
                        if (senate[stD] == 'D' && !used[stD]) break;
                        stD = (stD + 1) % len;
                    }
                    if (stD == i) return "Radiant";
                    used[stD] = true;
                } else {
                    int stD = (i + 1) % len;
                    while (stD != i) {
                        if (senate[stD] == 'R' && !used[stD]) break;
                        stD = (stD + 1) % len;
                    }
                    if (stD == i) return "Dire";
                    used[stD] = true;
                }
            }
        }
        return "Dire";
    }
};
