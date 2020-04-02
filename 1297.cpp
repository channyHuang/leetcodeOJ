class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        if (s.length() < minSize) return 0;
        int count[26];
        memset(count, 0, sizeof(count));
        map<string, int> maps;
        map<string, int>::iterator itr;
        int letters = 0;
        for (int i = 0; i < minSize; i++) {
            if (count[s[i] - 'a'] == 0) letters++;
            count[s[i] - 'a']++;
        }
        if (letters <= maxLetters) {
            itr = maps.find(s.substr(0, minSize));
            if (itr != maps.end()) itr->second++;
            else maps.insert(pair<string, int>(s.substr(0, minSize), 1));
        }
        for (int i = minSize; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 0) letters++;
            count[s[i] - 'a']++;
            count[s[i - minSize] - 'a']--;
            if (count[s[i - minSize] - 'a'] == 0) letters--;
            if (letters <= maxLetters) {
                map<string, int>::iterator itr = maps.find(s.substr(i - minSize + 1, minSize));
                if (itr != maps.end()) itr->second++;
                else maps.insert(pair<string, int>(s.substr(i - minSize + 1, minSize), 1));
            }
        }
        int res = 0;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second > res) res = itr->second;
        }
        return res;
    }
};
