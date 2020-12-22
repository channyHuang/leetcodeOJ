class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int res= 0;
        for (int i = 0; i < len; i++) {
            if (n[i] - '0' > res) {
                res = n[i] - '0';
            }
        }
        return res;
    }
};
