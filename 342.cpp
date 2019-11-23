class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        if (num % 2) return false;
        if (num == 4 || num == 16 || num == 64 || num == 256 || num == 1024) return true;
        if (num == 4096) return true;
        if (num == 16384) return true;
        if (num == 65536) return true;
        if (num == 262144) return true;
        if (num == 1048576) return true;
        if (num == 4194304) return true;
        if (num == 16777216) return true;
        if (num == 67108864) return true;
        if (num == 268435456) return true;
        if (num == 1073741824) return true;
        return false;
    }
};
