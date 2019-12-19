class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
         int count[26] = {0};
         for (int i = 0; i < licensePlate.length(); i++) {
             if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z') count[licensePlate[i] - 'a']++;
             else if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') count[licensePlate[i] - 'A']++;
         }
         int index = 0;
         int len = 10000;
         for (int i = 0; i < words.size(); i++) {
             int nums[26] = {0}, j = 0;
             for (j = 0; j < words[i].length(); j++) {
                 if (words[i][j] >= 'a' && words[i][j] <= 'z') nums[words[i][j] - 'a']++;
                 else if (words[i][j] >= 'A' && words[i][j] <= 'A') nums[words[i][j] - 'A']++;
            }
            for (j = 0; j < 26; j++) {
                if (count[j] == 0) continue;
                if (nums[j] < count[j]) break;
            }
            if (j == 26) {
                if (words[i].length() < len) {
                    len = words[i].length();
                    index = i;
                }
            }
         }
         return words[index];
    }
};
