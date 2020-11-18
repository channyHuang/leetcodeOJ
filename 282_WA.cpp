class Solution {
public:
    vector<string> addOperators(string num, int target) {
        len = num.size();
        res.clear();
        if (len <= 0) return res;
        m_target = target;
        m_starget = to_string(target);
        string str(len * 2, 0);
        str[0] = num[0];
        //a+b*c c:curNum, *:lastOpe, b:preNum, +:preOpe, a:fisrtNum
        search(num, 1, str, 1, num[0] - '0', 0, 0, '+', '+');

        /*
        cout << --- << num << --- << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
        cout << --- << endl;*/


        return res;
    }

/*
    void search(string& num, int stPos, string& curstr, int curlen, string curNum, string lastNum, string firstNum, char lastOpe, char preOpe) {
        if (stPos >= len) {
            string result = firstNum;
            if (lastOpe == '*') {
                string tmpres = multipleString(lastNum, curNum);
                switch(preOpe) {
                case '+':
                    result = addString(result, tmpres);
                    break;
                case '-':
                    result = minusString(rsult, tmpres);
                    break;
                case '*':
                    result = multipleString(result, tmpres);
                    break;
                }
            } else {


            }


            if (result == m_target) {
                res.push_back(curstr.substr(0, curlen));
            }
            return;
        }
    }*/


    void search(string& num, int stPos, string& curstr, int curlen, double curNum, double lastNum, double firstNum, char lastOpe, char preOpe) {
        if (stPos >= len) {
            //cout << curstr.substr(0, curlen) << endl;
            double result = firstNum;


            if (lastOpe == '*') {
                double tmpres = lastNum * curNum;
                switch(preOpe) {
                case '+':
                    result += tmpres;
                    break;
                case '-':
                    result -= tmpres;
                    break;
                case '*':
                    result *= tmpres;
                    break;
                }
            } else {
                switch(preOpe) {
                case '+':
                    result += lastNum;
                    break;
                case '-':
                    result -= lastNum;
                    break;
                case '*':
                    result *= lastNum;
                    break;
                }
                switch(lastOpe) {
                case '+':
                    result += curNum;
                    break;
                case '-':
                    result -= curNum;
                    break;
                case '*':
                    result *= curNum;
                    break;
                }
            }


            if (result == m_target) {
                res.push_back(curstr.substr(0, curlen));
            }
            return;
        }


        for (int j = 0; j < operators.size(); j++) {
            if (operators[j] == ' ') {
                if (num[stPos - 1] == '0') continue;
                curstr[curlen] = num[stPos];
                search(num, stPos + 1, curstr, curlen + 1, curNum * 10 + num[stPos] - '0', lastNum, firstNum, lastOpe, preOpe);
            } else {
                curstr[curlen] = operators[j];
                curstr[curlen + 1] = num[stPos];


                if (lastOpe == '*') {
                    search(num, stPos + 1, curstr, curlen + 2, num[stPos] - '0', lastNum * curNum, firstNum, operators[j], preOpe);
                } else {
                    double tmp = firstNum;
                    switch (preOpe) {
                    case '+':
                        tmp += lastNum;
                        break;
                    case '-':
                        tmp -= lastNum;
                        break;
                    case '*':
                        tmp *= lastNum;
                        break;
                    }


                    search(num, stPos + 1, curstr, curlen + 2, num[stPos] - '0', curNum, tmp, operators[j], lastOpe);
                }


            }
        }
    }


    string revertString(const string& a) {
        string res = a;
        int stPos = 0;
        int endPos = a.length() - 1;
        while (endPos > 0 && a[endPos] == '0') endPos--;
        if (endPos == 0) return a.substr(0, 1);
        while (stPos < endPos) {
            char tmp = res[stPos];
            res[stPos] = res[endPos];
            res[endPos] = tmp;
            stPos++;
            endPos--;
        }
        return res;
    }


    bool smaller(const string& a, const string& b) {
        if (a.length() > b.length()) return false;
        if (a.length() < b.length()) return true;
        int len = a.length();
        for (int i = 0; i < len; i++) {
            if (a[i] > b[i]) return false;
            else if (a[i] < b[i]) return true;
        }
        return false;
    }


    string minusString(const string& a, const string& b) {
        if (a[0] == '-' && b[0] == '-') {
            return minusString(b.substr(1), a.substr(1));
        }
        if (a[0] == '-') {
            return "-" + addString(a.substr(1), b);
        }
        if (b[0] == '-') {
            return addString(a, b.substr(1));
        }
        if (smaller(a, b)) return "-" + minusString(b, a);
        int lena = a.length();
        int posb = b.length() - 1;
        string res(lena, 0);
        int lenr = 0;




        int minus = 0;
        for (int i = lena - 1; i >= 0; i--) {
            int tmp = 0;
            if (posb < 0) {
                tmp = a[i] - '0' - minus;
                minus = 0;
                if (tmp < 0) {
                    tmp += 10;
                    minus = 1;
                }
            } else {
                tmp = a[i] - b[posb--] - minus;
                if (tmp < 0) {
                    tmp += 10;
                    minus = 1;
                }
            }
            res[lenr++] = tmp + '0';
        }
        return revertString(res.substr(0, lenr));
    }


    string addString(const string& a, const string& b) {
        if (a[0] == '-' && b[0] == '-') {
            return "-" + addString(a.substr(1), b.substr(1));
        }
        if (a[0] == '-') {
            return minusString(b, a.substr(1));
        }
        if (b[0] == '-') {
            return minusString(a, b.substr(1));
        }


        int lena = a.length();
        int lenb = b.length();
        int add = 0;
        string res(max(lena, lenb) + 1, 0);
        int posb = lenb - 1, posa = lena - 1;
        int lenr = 0;
        while (posa >= 0 && posb >= 0) {
            int tmp = a[posa] - '0' + b[posb] - '0' + add;
            add = 0;
            if (tmp >= 10) {
                tmp %= 10;
                add = 1;
            }
            res[lenr++] = tmp + '0';
            posa--;
            posb--;
        }
        while (posa >= 0) {
            int tmp = a[posa] - '0' + add;
            add = 0;
            if (tmp >= 10) {
                tmp %= 10;
                add = 1;
            }
            res[lenr++] = tmp + '0';
            posa--;
        }
        while (posb >= 0) {
            int tmp = b[posb] - '0' + add;
            add = 0;
            if (tmp >= 10) {
                tmp %= 10;
                add = 1;
            }
            res[lenr++] = tmp + '0';
            posb--;
        }


        return revertString(res.substr(0, lenr));
    }


    string multipleCharString(const string& a, const char c) {
        int lena = a.length();
        string res(lena + 1, 0);
        int lenr = 0;
        int add = 0;
        for (int i = lena - 1; i >= 0; i--) {
            int tmp = (a[i] - '0') * (c - '0') + add;
            add = 0;
            if (tmp > 10) {
                add = tmp / 10;
                tmp %= 10;
            }
            res[lenr++] = tmp + '0';
        }
        while (add) {
            res[lenr++] = add % 10 + '0';
            add /= 10;
        }
        return revertString(res.substr(0, lenr));
    }


    string multipleString(const string& a, const string& b) {
        if (a[0] == '-' && b[0] == '-') {
            return multipleString(a.substr(1), b.substr(1));
        }
        if (a[0] == '-') {
            return "-" + multipleString(a.substr(1), b);
        }
        if (b[0] == '-') {
            return "-" + multipleString(a, b.substr(1));
        }
        
        int lenb = b.length();
        string res = 0;
        int countZero = 0;
        for (int i = lenb - 1; i >= 0; i--) {
            string tmp = multipleCharString(a, b[i]);
            for (int j = 0; j < countZero; j++) {
                tmp += "0";
            }
            res = addString(res, tmp);
            countZero++;
        }
        return res;
    }




private:
    int len;
    vector<string> res;
    vector<vector<string>> dp;
    vector<char> operators = {'+', '-', '*', ' '};
    int m_target;
    string m_starget;
};
