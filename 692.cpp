class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        int len = words.size();
        map<string, int> maps;
        map<string, int>::iterator itr;
        map<string, int>::iterator itr2;
        vector<string> res;
        res.resize(k);
        for (int i = 0; i < len; i++) {
            itr = maps.find(words[i]);
            if (itr == maps.end()) {
                maps.insert(pair<string, int>(words[i], 1));
            } else itr->second++;
        }
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            int count = 0;
            for (itr2 = maps.begin(); itr2 != maps.end(); itr2++) {
                if (itr == itr2) continue;
                if (itr2->second > itr->second || (itr2->second == itr->second && itr->first > itr2->first)) count++;
            }
            if (count < k) res[count] = (itr->first);
        }
        return res;
    }
};
