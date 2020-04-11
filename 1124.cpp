class Solution {
public:
    int longestWPI(vector<int>& hours) {
       int len = hours.size();
       if (len <= 0) return 0;
       int res = 0;
       int maxn[len];
       memset(maxn, 0, sizeof(maxn));
       if (hours[0] > 8) {
           maxn[0] = 1;
           res = 1;
       }
       for (int i = 1; i < len; i++) {
           if (hours[i] > 8) {
               maxn[i] = maxn[i - 1] + 1;
               //res = max(res, 1);
           }
           else maxn[i] = maxn[i - 1];
           if (maxn[i] > (i + 1) / 2) {
               res = max(res, i + 1);
               continue;
           }
           for (int j = 0; j < i; j++) {
               if (i - j <= res) break;
               if (maxn[i] - maxn[j] > (i - j) / 2) res = max(res, i - j); 
           }
       }
       return res;
    }
};
