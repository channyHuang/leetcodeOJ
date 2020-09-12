class Solution {
public:
    int numWays(string s) {
        long long len = s.length();
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') count++;
        }
        if (count % 3 != 0) return 0;
        if (count == 0) return (long long)(len - 1) * (len - 2) / 2 % 1000000007;
        count /= 3;
        int cnt = 0;
        long long left = 0, right = len - 1;
        while (left < len) {
            if (s[left++] == '1') {
                cnt++;               
                if (cnt == count) break;
            }
        }
        cnt = 0;
        while (right >= 0) {
            if (s[right--] == '1') {
                cnt++;                
                if (cnt == count) break;
            }
        }
        //cout << left << " " << right << endl;
        int nleft = 0, nright = 0;
        while (s[left] == '0') {
            left++;
            nleft++;
        }
        while (s[right] == '0') {
            right--;
            nright++;
        }
        return (long long)(nleft + 1) * (nright + 1) % 1000000007;
    }
};
