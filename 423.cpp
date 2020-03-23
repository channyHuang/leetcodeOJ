class Solution {
public:
    string originalDigits(string s) {
        vector<string> numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        int sum[10] = {0};
        vector<int> singlenum = {0, 2, 4, 6, 7, 5, 8, 9, 3, 1};
        vector<char> single = {'z', 'w', 'u', 'x', 's', 'v', 'g', 'i', 'r', 'o'};
        for (int i = 0; i < 10; i++) {
            if (count[single[i] - 'a']) {
                sum[singlenum[i]] = count[single[i] - 'a'];
                for (int j = 0; j < numbers[singlenum[i]].length(); j++) {
                    count[numbers[singlenum[i]][j] - 'a'] -= sum[singlenum[i]];
                }
            }
        }
        string res = "";
        for (int i = 0; i < 10; i++) {
            while (sum[i]) {
                res += to_string(i);
                sum[i]--;
            }
        }
        return res;
    }
};
