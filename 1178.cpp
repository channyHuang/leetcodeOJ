class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        //puzzles[i].length == 7
        int wlen = words.size();
        int plen = puzzles.size();
        vector<int> res(plen, 0);
        for (int i = 0; i < wlen; i++) {
            int whash = 0;
            for (int j = 0; j < words[i].length(); j++) {
                whash |= (1 << (words[i][j] - 'a'));
            }
            maps[whash]++;
        }
        for (int i = 0; i < plen; i++) {
            int phash = 0;
            for (int j = 0; j < puzzles[i].length(); j++) {
                phash |= (1 << (puzzles[i][j] - 'a'));
            }

            for (int j = phash; j; j = ((j - 1) & phash)) {
                if ((j & (1 << (puzzles[i][0] - 'a'))) == 0) continue;
                unordered_map<int, int>::iterator itr = maps.find(j);
                if (itr != maps.end()) {
                    res[i] += itr->second;
                }
            }
            /*TLE
            for (unordered_map<int, int>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
                if ((itr->first & (1 << (puzzles[i][0] - 'a'))) == 0) continue;
                if ((itr->first & phash) != itr->first) continue;
                res[i] += itr->second;
            }*/
        }
        return res;
    }

private:
    unordered_map<int, int> maps;
};
