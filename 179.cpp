class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s = "123456789012345";
        int slen = s.length();
        int len = nums.size();
        int count0 = 0;
        string res = "";
        if (len <= 0) return "";
        vector<string> vec;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                count0++;
                continue;
            }
            int pos = slen;
            int tmp = nums[i];
            while (tmp) {
                s[--pos] = tmp % 10 + '0';
                tmp /= 10;
            }
            vec.push_back(s.substr(pos));
        }
        if (vec.size() > 0)
            sort(vec.begin(), vec.end(), cmp);
        
        for (int i = 0; i < vec.size(); i++) {
            res += vec[i];
        }
        if (res.length() == 0) return "0";
        while (count0) {
            res += "0";
            count0--;
        }
        return res;
    }

    static bool cmp(const string& a, const string& b) {
        int pos = 0;
        int len = a.length() + b.length();
        string ab = a + b;
        string ba = b + a;
        for (int i = 0; i < len; i++) {
            if (ab[i] != ba[i]) return ab[i] > ba[i];
        }
        return false;
    }
};
