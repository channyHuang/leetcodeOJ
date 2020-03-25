class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> res;
        if (len < 10) return res;
        int count[len];
        memset(count, 0, sizeof(count));
        map<int, int> maps;
        map<int, int>::iterator itr;
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum = (sum << 2) + change(s[i]);
        }
        maps.insert(pair<int, int>(sum, 0));
        count[0]++;
        for (int i = 10; i < len; i++) {
            sum -= change(s[i - 10]) * 262144;
            sum = (sum << 2) + change(s[i]);
            itr = maps.find(sum);
            if (itr == maps.end()) {
                maps.insert(pair<int, int>(sum, i - 9));
                count[i - 9]++;
                continue;
            }
            if (count[itr->second] > 1) continue;
            count[itr->second]++;
            res.push_back(s.substr(itr->second, 10));
        }
        return res;
    }

    int change(char c) {
        switch(c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        default:
            return 0;
        }
    }
};
