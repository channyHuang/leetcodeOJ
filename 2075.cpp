class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        if (len == 0) return "";
        string res;
        int cols = len / rows;
        for (int j = 0; j <= (cols - rows) + 1; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (i + j >= cols) break;
                int idx = getindex(rows, cols, i, i + j);
                res += encodedText.substr(idx, 1);
            }
        }
        int pos = res.length() - 1;
        while (res[pos] == ' ') pos--;
        return res.substr(0, pos + 1);
    }

    int getindex(int rows, int cols, int i, int j) {
        return (i * cols + j);
    }
};
