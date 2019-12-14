class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        if (len <= 1) return true;
        for (int i = 0; i < len; i++) {
            if (i == len - 1) return true;
            if (bits[i] == 1) i++;
        }
        return false;
    }
};
