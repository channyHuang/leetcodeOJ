class Solution {
public:
    // a < b: true
    static bool cmp(const string &a, const string &b) {
        int lena = a.length();
        int lenb = b.length();
        if (lena <= 0) return true;
        if (lenb <= 0) return false;
        int minlen = std::min(lena, lenb);
        for (int i = 0; i < minlen; ++i) {
            if (a[i] > b[i]) return false;
            else if (b[i] > a[i]) return true;
        }
        if (lena == lenb) return true;
        if (minlen < lena) {
            for (int i = 0; i < lena; ++i) {
                if (minlen + i < lena) {
                    if (a[minlen + i] < a[i]) return true;
                    else if (a[minlen + i] > a[i]) return false;
                } else {
                    if (a[minlen + i - lena] < a[i]) return true;
                    else if (a[minlen + i - lena] > a[i]) return false;
                }
            }
        } else if (minlen < lenb) {
            for (int i = 0; i < lenb; ++i) {
                if (minlen + i < lenb) {
                    if (b[minlen + i] < b[i]) return false;
                    else if (b[minlen + i] > b[i]) return true;
                } else {
                    if (b[minlen + i - lenb] < b[i]) return false;
                    else if (b[minlen + i - lenb] > b[i]) return true;
                }
            }
        }
        return true;
    }

    string minNumber(vector<int>& nums) {
        int len = nums.size();
        cout << len << endl;
        vector<string> str;
        for (int i = 0; i < len; ++i) {
            str.push_back(to_string(nums[i]));
        }
        for (int i = 1; i < len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (!cmp(str[j], str[j + 1])) {
                    string tmp = str[j + 1];
                    str[j + 1] = str[j];
                    str[j] = tmp;
                } else {
                    break;
                }

            }
        }
        
        string res;
        for (int i = 0; i < len; ++i) {
            res += str[i];
        }
        return res;
    }
};
