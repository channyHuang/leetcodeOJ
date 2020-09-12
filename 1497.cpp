class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if (k == 1) return true;
        int len = arr.size();
        int cnt = 0;
        map<int, int> rest;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            //while (arr[i] < 0) arr[i] += k;
            int r = (arr[i] + k) % k;
            while (r < 0) r = (r + k) % k;
            
            if (r == 0) {
                itr = rest.find(r);
                if (itr == rest.end() || itr->second == 0) rest[r] = 1;
                else {
                    rest[r]--;
                    cnt++;
                }
            } else {
                itr = rest.find(k - r);
                if (itr == rest.end() || itr->second == 0) rest[r]++;
                else {
                    rest[k - r]--;
                    cnt++;
                }
            }
        }
        return cnt == (len >> 1);
    }
};
