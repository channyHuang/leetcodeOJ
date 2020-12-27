class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.length();
        vector<int> index;
        for (int i = 0; i < len; i++) {
            if (binary[i] == '0') {
                index.push_back(i);
                binary[i] = '1';
            }           
        }
        int ilen = index.size();
        for (int i = 0; i < ilen; i++) {
            if (i == ilen - 1) break;
            if (index[i + 1] == index[i] + 1) continue;
            index[i + 1] = index[i] + 1;
        }
        if (ilen > 0) {
            binary[index[ilen - 1]] = '0';
        }
        return binary;
    }
};
