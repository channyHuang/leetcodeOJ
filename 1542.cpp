class Solution {
public:
    int longestAwesome(string s) {
        int len = s.length();
        if (len == 0) return 0;
        int res = 1;
        int hashValue = 0;
        std::unordered_map<int, int> hashMap;
        std::unordered_map<int, int>::iterator mapItr;
        hashMap.insert(std::make_pair(0, -1));
        for (int i = 0; i < len; i++) {
            hashValue ^= (1 << (s[i] - '0'));

            mapItr = hashMap.find(hashValue);
            if (mapItr != hashMap.end()) {
                res = std::max(res, i - mapItr->second);
            }
            for (int j = 0; j < 10; j++) {
                int tmpHash = (hashValue ^ (1 << j));
                mapItr = hashMap.find(tmpHash);
                if (mapItr != hashMap.end()) {
                    res = std::max(res, i - mapItr->second);
                }
            }

            hashMap.insert(std::make_pair(hashValue, i));
        }
        return res;
    }
};
