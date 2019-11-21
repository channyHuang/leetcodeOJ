class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int res = 0;
        for (int i = 0; i < 3; i++) {
            res += (guess[i] == answer[i] ? 1 : 0);
        }   
        return res;
    }
};
