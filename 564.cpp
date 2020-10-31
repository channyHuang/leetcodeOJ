class Solution {
public:
    string nearestPalindromic(string n) {
        long long origin = stoll(n);
        int len = n.length();
        if (len == 1) {
            if (origin == 0) return "1";
            return to_string(origin - 1);
        }
        set<string> sets;
        sets.insert(to_string(pow(10, len) + 1));
        sets.insert(to_string(pow(10, len - 1) - 1));
        
        int mid = len / 2;
        if (len & 1) {
            long long left = stoll(n.substr(0, mid));
            for (int i = -1; i <= 1; i++) {
                string sleft = to_string(left + i);
                string rleft = string(sleft.rbegin(), sleft.rend());

                sets.insert(sleft + to_string(n[mid] - '0') + rleft);
                if (n[mid] > '0') sets.insert(sleft + to_string(n[mid] - '0' - 1) + rleft);
                if (n[mid] < '9') sets.insert(sleft + to_string(n[mid] - '0' + 1) + rleft);
            }

        } else {
            long long left = stoll(n.substr(0, mid));
            for (int i = -1; i <= 1; i++) {
                string sleft = to_string(left + i);
                string rleft = string(sleft.rbegin(), sleft.rend());
                sets.insert(sleft + rleft);
            }
        }
        
        sets.erase(n);
        
        long long diff = LONG_MAX;
        long long res = origin;

        for (set<string>::iterator itr = sets.begin(); itr != sets.end(); itr++) {
            //cout << *itr << " ";
            long long vecn = stoll(*itr);
            long long ndiff = (vecn > origin ? vecn - origin : origin - vecn);
            
            if (ndiff < diff || ((ndiff == diff) && (vecn < res))) {
                diff = ndiff;
                res = vecn;
            }
        }
        //cout << "---" << endl;
        return to_string(res);
    }
};
