class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if (numerator == 0) return "0";
        long long lnum = numerator;
        long long lden = denominator;
        bool positive = true;
        if (lnum < 0) {
            lnum = -lnum;
            positive = !positive;
        }
        if (lden < 0) {
            lden = -lden;
            positive = !positive;
        }
        res += to_string(lnum / lden);
        lnum %= lden;     
        if (lnum == 0) return (positive ? res : "-" + res);
        res += ".";
        map<long long, int> maps;
        map<long long, int>::iterator itr;
        while (lnum) {
            itr = maps.find(lnum);
            if (itr != maps.end()) {
                res.insert(itr->second, "(");
                res += ")";
                break;
            }
            maps.insert(pair<long long, int>(lnum, res.length()));
            if (lnum < lden) lnum *= 10;
            res += to_string(lnum / lden);
            lnum %= lden;
        }
        return (positive ? res : "-" + res);
    }
};
