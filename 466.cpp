class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length();
        int len2 = s2.length();

        vector<int> round(len2, 0);
        vector<int> nextPos(len2, 0);
        for (int i = 0; i < len2; i++) {
            nextPos[i] = i;
            for (int j = 0; j < len1; j++) {
                if (s1[j] != s2[nextPos[i]]) continue;
                nextPos[i]++;
                if (nextPos[i] >= len2) {
                    round[i]++;
                    nextPos[i] = 0;
                }
            }
        }
/*
        for (int i = 0; i < len2; i++) {
            cout << round[i] << " " << nextPos[i] << endl;
        }
*/
        int sum = 0;
        int stPos = 0;
        for (int i = 0; i < n1; i++) {
            sum += round[stPos];
            stPos = nextPos[stPos];
        }

        return sum / n2;
    }
};