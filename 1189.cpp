class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int len = text.length();
        int count[26] = {0};
        for (int i = 0; i < len; i++ ) {
            count[text[i] - 'a']++;
        }
        int res = count[1];//'b'
        if (count[0] < res) res = count[0];
        if (count['n' - 'a'] < res) res = count['n' - 'a'];
        if (count['l' - 'a'] / 2 < res) res = count['l' - 'a'] / 2;
        if (count['o' - 'a'] / 2 < res) res = count['o' - 'a'] / 2;
        return res;
    }
};
