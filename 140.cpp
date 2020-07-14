class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = wordDict.size();
        if (len <= 0) return res;
        bool appear[26];
        memset(appear, 0, sizeof(appear));
        for (int i = 0; i < len; i++) {
            maps[wordDict[i]] = true;
            for (char c : wordDict[i]) {
                appear[c - 'a'] = true;
            }
            if(maxlen < wordDict[i].length()) maxlen = wordDict[i].length();
        }
        len = s.length();
        for (int i = 0; i < len; i++) {
            if (appear[s[i] - 'a'] == false) return res;
        }
        used.resize(len, false);
        dp[len] = vector<string>(1, "");

        for (int i = len; i >= 0; i--) {
            if (dp[i].size() > 0) split(s, i);
        }

        return dp[0];
    }

    void split(string s, int endPos) {
        for (int i = endPos - 1; i >= 0; i--) {
            if (maps.find(s.substr(i, endPos - i)) == maps.end()) continue;
            for (int j = 0; j < dp[endPos].size(); j++) {
                dp[i].push_back(s.substr(i, endPos - i) + (endPos == len ? "" : " ") + dp[endPos][j]);
            }
        }
    }

private:
    unordered_map<string, bool> maps;
    vector<string> res;
    int len;
    int maxlen = 0;
    unordered_map<int, vector<string>> dp;
    vector<bool> used;
};
