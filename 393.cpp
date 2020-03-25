class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        if (len <= 0) return false;
        
        for (int i = 0; i < len; i++) {
            data[i] &= 255;
            if (data[i] < 128) {
                continue;
            } else if ((data[i] ^ 192) < 32) {
                if (i >= len - 1) return false;
                data[++i] &= 255;
                if ((data[i] ^ 128) >= 64) return false;
                continue;
            } else if ((data[i] ^ 224) < 16) {
                if (i >= len - 2) return false;
                data[++i] &= 255;
                if ((data[i] ^ 128) >= 64) return false;
                data[++i] &= 255;
                if ((data[i] ^ 128) >= 64) return false;
                continue;
            } else if ((data[i] ^ 240) < 8) {
                if (i >= len - 3) return false;
                data[++i] &= 255;
                if ((data[i] ^ 128) >= 64) return false;
                data[++i] &= 255;
                if ((data[i] ^ 128) >= 64) return false;
                data[++i] &= 255;
                if ((data[i] ^ 128) >= 64) return false;
                continue;
            } else return false;            
        }
        return true;
    }
};
