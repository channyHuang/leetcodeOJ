class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        long long num = 0;
        nNum = nOpe = 0;
        stNum.resize(len, 0);
        stOpe.resize(len, ' ');
        bool bNum = false;
        for (int i = 0; i < len; i++) {
#ifdef DEBUG_OUTPUT
            qDebug() << "start-----" << s[i];
            for (int i = 0; i < nNum; i++) {
                cout << stNum[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < nOpe; i++) {
                cout << stOpe[i] << " ";
            }
            cout << endl;
            qDebug() << "end-----" << s[i];
#endif
            if (s[i] >= '0' && s[i] <= '9') {
                if (!bNum) num = 0;
                num = num * 10 + s[i] - '0';
                bNum = true;
                continue;
            }
            if (s[i] == ' ') continue;
            if (s[i] == '+' || s[i] == '-') {
                if (nNum == 0 || stOpe[nOpe - 1] == '(') {
                    stNum[nNum++] = num;
                } else {
                    int lastNum = stNum[--nNum];
                    char lastOpe = stOpe[--nOpe];
                    stNum[nNum++] = ((lastOpe == '+') ? (lastNum + num) : (lastNum - num));
                }
                stOpe[nOpe++] = s[i];
            } else if (s[i] == '(') {
                stOpe[nOpe++] = s[i];
            } else if (s[i] == ')') {
                if (stOpe[nOpe - 1] == '(') {
                    --nOpe;
                    continue;
                }
                int lastNum = stNum[--nNum];
                char lastOpe = stOpe[--nOpe];
                nOpe--;
                num = (lastOpe == '+' ? (lastNum + num) : (lastNum - num));
            }
            bNum = false;
        }

        while (nOpe > 0) {
            long long lastNum = stNum[--nNum];
            char lastOpe = stOpe[--nOpe];
            lastNum = (lastOpe == '+' ? (lastNum + num) : (lastNum - num));
            num = lastNum;
        }
        return num;
    }
private:
    vector<long long> stNum;
    int nNum;
    vector<char> stOpe;
    int nOpe;
};
