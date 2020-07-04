class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res;
        string numstr = to_string(num);
        int len = numstr.length();
        int left = len % 3;
        if (left != 0) {
            res = part(numstr, 0, left - 1);
            string stLevel = level(len - left);
            if (stLevel.length() > 0) res += " " + stLevel;
        }

        for (int i = left; i < len; i += 3) {
            string tmp = part(numstr, i, i + 2);
            string stLevel = level(len - i - 3);
            if (tmp.length() > 0 && stLevel.length() > 0) tmp += " " + stLevel;
            if (res.length() > 0 && tmp.length() > 0) res += " ";
            res += tmp;
        }
        std::cout << res << std::endl;
        return res;
    }

    string level(int left) {
        switch (left) {
        case 3:
        case 6:
        case 9:
            return levels[left / 3];
        case 0:
        default:
            return "";
        }
    }

    string part(string numstr, int stPos, int endPos) {
        while (stPos <= endPos && numstr[stPos] == '0') stPos++;
        if (stPos > endPos) return "";
        if (stPos == endPos) return bit1[numstr[stPos] - '0'];
        if (stPos == endPos - 1) {
            if (numstr[stPos] == '1') return bit2[numstr[endPos] - '0'];
            return bit3[numstr[stPos] - '2'] + (numstr[endPos] == '0' ? "" : " " + bit1[numstr[endPos] - '0']);
        }
        string substr = part(numstr, stPos + 1, endPos);
        return bit1[numstr[stPos] - '0'] + " Hundred" + (substr.length() > 0 ? " " + substr : "");
    }

private:
    vector<string> bit1 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> bit2 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> bit3 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> levels = {"", "Thousand", "Million", "Billion"};
};
