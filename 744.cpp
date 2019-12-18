class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int res = 'z' + 26;
        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] == target) continue;
            int tmp = letters[i];
            if (letters[i] < target) {
                tmp += 26;
            }
            res = min(res, tmp);
        }
        if (res > 'z' || res < 'a') res -= 26;
        return res;
    }
};
