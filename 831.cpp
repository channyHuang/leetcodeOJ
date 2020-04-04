class Solution {
public:
    string maskPII(string S) {
        int len = S.length();
        bool email = false;
        if (S[0] >= 'a' && S[0] <= 'z') email = true;
        if (S[0] >= 'A' && S[0] <= 'Z') email = true;
        if (email) {
            string::size_type pos = S.find_first_of("@", 0);
            if (S[0] >= 'A' && S[0] <= 'Z') S[0] = S[0] - 'A' + 'a';
            S.replace(1, pos - 2, "*****");
            pos = S.find_first_of("@", 0);
            for (int i = pos - 1; i < S.length(); i++) {
                if (S[i] >= 'A' && S[i] <= 'Z') S[i] = S[i] - 'A' + 'a'; 
            }
            return S;
        }
        int count = 0;
        string res = "***-***-0000";
        int pos = res.length() - 1;
        int nums = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (S[i] >= '0' && S[i] <= '9') {
                nums++;
                if (count >= 4) continue;
                count++;
                res[pos--] = S[i];
                
            }
        }
        if (nums > 10) {
            string sub = "*";
            for (int i = 1; i < nums - 10; i++) sub += "*";
            res = "+" + sub + "-" + res;
        }
        return res;
    }
};
