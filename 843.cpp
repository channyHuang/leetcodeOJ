/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int len = wordlist.size();
        same.resize(len, vector<int>(len, 0));
        valid.resize(len, true);
        for (int i = 0; i < len; i++) {
            same[i][i] = 6;
            for (int j = i + 1; j < len; j++) {
                same[i][j] = sameCount(wordlist[i], wordlist[j]);
                same[j][i] = same[i][j];
            }
        }
        while (1) {
            int index = 0;
            int minn = INT_MAX;
            
            for (int i = 0; i < len; i++) {
                if (!valid[i]) continue;
                int count[7] = {0};
                for (int j = 0; j < len; j++) {
                    if (!valid[i]) continue;
                    count[same[i][j]]++;
                }
                int maxn = count[0];
                for (int j = 1; j < 7; j++) {
                    maxn = max(maxn, count[j]);
                }

                if (maxn < minn) {
                    minn = maxn;
                    index = i;
                }
            }
            //cout << index << " " << wordlist[index] << endl;
            int guessRes = master.guess(wordlist[index]);
            if (guessRes == 6) return;
            else {
                for (int i = 0; i < len; i++) {
                    if (same[index][i] != guessRes) valid[i] = false;
                }
            }
        }
    }

    int sameCount(string a, string b) {
        int res = 0;
        for (int i = 0; i < 6; i++) {
            if (a[i] == b[i]) res++;
        }
        return res;
    }

private:
    vector<vector<int>> same;
    vector<bool> valid;
};
