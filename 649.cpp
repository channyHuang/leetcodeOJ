class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();
        int cnt = 1;
        for (int i = 1; i < len; i++) {
            if (senate[i] == senate[0]) cnt++;
        }
        if (cnt >= len - cnt) return (senate[0] == 'R' ? "Radiant" : "Dire");
        return (senate[0] == 'R' ? "Dire" : "Radiant");
    }
};
