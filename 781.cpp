class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int len = answers.size();
        if (len <= 0) return 0;
        if (len == 1) return answers[0] + 1;
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(answers[i]);
            if (itr == maps.end()) maps.insert(pair<int, int>(answers[i], 1));
            else itr->second++;
        }
        int res = 0;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            int count = itr->second / (itr->first + 1);
            int left = itr->second % (itr->first + 1);
            res += (count * (itr->first + 1));
            if (left > 0) res += (itr->first + 1);
        }
        return res;
    }
};
