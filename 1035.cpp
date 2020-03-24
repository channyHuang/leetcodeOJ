class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lena = A.size();
        int lenb = B.size();
        int dp[lena + 5][lenb + 5];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < lena; i++) {
            for (int j = 0; j < lenb; j++) {
                if (A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[lena][lenb];
    }
};
/*TLE
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int lena = A.size();
        int lenb = B.size();
        if (lena <= 0 || lenb <= 0) return 0;
        set<int> seta;
        bool useda[505] = {0}, usedb[505] = {0};
        vector<vector<int>> infoA, infoB;
        infoA.resize(2005);
        infoB.resize(2005);
        for (int i = 0; i < lena; i++) {
            seta.insert(A[i]);
        }
        for (int i = 0; i < lenb; i++) {
            if (seta.find(B[i]) == seta.end()) {
                usedb[i] = true;
                continue;
            }
            infoB[B[i]].push_back(i);
        }
        for (int i = 0; i < lena; i++) {
            if (infoB[A[i]].size() == 0) {
                useda[i] = true;
                continue;
            }
            infoA[A[i]].push_back(i);
        }
        int pos = 0;
        for (int i = 0; i <lena; i++) {
            if (useda[i]) continue;
            A[pos++] = A[i];
        }
        lena = pos;
        pos = 0;
        for (int i = 0; i < lenb; i++) {
            if (usedb[i]) continue;
            B[pos++] = B[i];
        }
        lenb = pos;
        return maxLines(A, B, infoA, infoB, 0, lena - 1, 0, lenb - 1);
    }

    int maxLines(vector<int>& A, vector<int>& B, vector<vector<int>>& infoA, vector<vector<int>>& infoB, int stA, int endA, int stB, int endB) {
        if (stA > endA || stB > endB) return 0;
        if (A[stA] == B[stB]) return 1 + maxLines(A, B, infoA, infoB, stA + 1, endA, stB + 1, endB);
        if (A[endA] == B[endB]) return 1 + maxLines(A, B, infoA, infoB, stA, endA - 1, stB, endB - 1);
        vector<int> next = infoB[A[stA]];
        int nextStB = -1;
        for (int i = 0; i < next.size(); i++) {
            if (next[i] < stB) continue;
            if (next[i] > endB) break;
            nextStB = next[i];
            break;
        }
        if (nextStB == -1) return maxLines(A, B, infoA, infoB, stA + 1, endA, stB, endB);
        int x = 1 + maxLines(A, B, infoA, infoB, stA + 1, endA, nextStB + 1, endB);
        int y = maxLines(A, B, infoA, infoB, stA + 1, endA, stB, endB);
        return max(x, y);
    }
};
*/
