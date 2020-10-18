class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int len = row.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            maps[row[i]] = i;
        }
        for (int i = 1; i < len; i += 2) {
            if (row[i - 1] & 1) {
                if (row[i] != row[i - 1] - 1) {
                    itr = maps.find(row[i - 1] - 1); 
                    int idx = itr->second;
                    maps[row[i]] = idx;                  
                    row[idx] = row[i];
                    row[i] = row[i - 1] - 1;
                    res++;
                    maps[row[i]] = i;                   
                } 
            } else {
                if (row[i] != row[i - 1] + 1) {
                    itr = maps.find(row[i - 1] + 1); 
                    int idx = itr->second;
                    maps[row[i]] = idx;                  
                    row[idx] = row[i];
                    row[i] = row[i - 1] + 1;
                    res++;
                    maps[row[i]] = i;
                }
            }
        }
        return res;
    }
private:
    map<int, int> maps;
    map<int, int>::iterator itr;
};
