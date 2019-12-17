class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        int count = 1;
        int pos = 0;
        int curC = 0;
        for (int i = 1; i < len; i++) {
            if (chars[i] == chars[curC]) count++;
            else {
                chars[pos] = chars[curC];
                curC = i;
                if (count == 1) {
                    pos++;
                    continue;
                }
                if (count < 10) {
                    chars[pos + 1] = count + '0';
                    pos += 2;
                } else if (count < 100) {
                    chars[pos + 1] = (count / 10) + '0';
                    chars[pos + 2] = (count % 10) + '0';
                    pos += 3;
                } else {
                    chars[pos + 1] = (count / 100) + '0';
                    chars[pos + 2] = (count / 10 % 10) + '0';
                    chars[pos + 3] = (count % 10) + '0';
                    pos += 4;
                }
                count = 1;
            }
        }
        chars[pos] = chars[curC];
         if (count == 1) return pos + 1;
         if (count < 10) {
                    chars[pos + 1] = count + '0';
                    pos += 2;
                } else if (count < 100) {
                    chars[pos + 1] = (count / 10) + '0';
                    chars[pos + 2] = (count % 10) + '0';
                    pos += 3;
                } else {
                    chars[pos + 1] = (count / 100) + '0';
                    chars[pos + 2] = (count / 10 % 10) + '0';
                    chars[pos + 3] = (count % 10) + '0';
                    pos += 4;
                }
                return pos;
    }
};
