class Solution {
public:
    vector<string> res;

    vector<string> readBinaryWatch(int num) {
        res.clear();

        if (num == 0) {
            res.push_back("0:00");
            return res;
        }

        bool flag[10] = {false};
        search(num, flag, 0);
        return res;
    }

    void search(int num, bool flag[10], int curPos) {
        if (num + curPos > 10) return;
        if (num == 0 || curPos >= 10) {
            if (num != 0) return;
            int hour = 0;
            int minu = 0;
            for (int i = 0; i < 4; i++) {
                hour = (hour << 1) + (flag[i] ? 1 : 0);
            }

            if (hour >= 12) return;

            for (int i = 4; i < 10; i++) {
                minu = (minu << 1) + (flag[i] ? 1 : 0);
            }

            if (minu >= 60) return;

            string time = itoa(hour) + ":" + itoa(minu, true);
            res.push_back(time);

            return;
        }
        
        flag[curPos] = true;
        search(num - 1, flag, curPos + 1);
        flag[curPos] = false;
        search(num, flag, curPos + 1);
    }

    string itoa(int n, bool fill = false) {
        string res = "";
        char str[2] = {0};
        while (n) {
            str[0] = n % 10 + '0';
            res = string(str) + res;
            n /= 10;
        }
        if (res.length() == 0) res = "0" + res;
        if (fill)
            while (res.length() < 2) res = "0" + res;
        return res;
    }
};
