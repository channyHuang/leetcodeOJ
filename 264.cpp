class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res;
        set<int> sets;
        int count = 3;
        int pointer[3] = {1,1,0}; //2,3,5
        res.push_back(1);
        res.push_back(2);
        res.push_back(3);
        sets.insert(1);
        sets.insert(2);
        sets.insert(3);
        while (count < n) {
            int a = res[pointer[0]] * 2;
            while (sets.find(a) != sets.end()) {
                pointer[0]++;
                a = res[pointer[0]] * 2;
            }
            int b = res[pointer[1]] * 3;
            while (sets.find(b) != sets.end()) {
                pointer[1]++;
                b = res[pointer[1]] * 3;
            }
            int c = res[pointer[2]] * 5;
            while (sets.find(c) != sets.end()) {
                pointer[2]++;
                c = res[pointer[2]] * 5;
            }
            if (a <= b) {
                if (a <= c) {
                    res.push_back(a);
                    pointer[0]++;
                    sets.insert(a);
                } else {
                    res.push_back(c);
                    pointer[2]++;
                    sets.insert(c);
                }
            } else if (b <= c) {
                res.push_back(b);
                pointer[1]++;
                sets.insert(b);
            } else {
                res.push_back(c);
                pointer[2]++;
                sets.insert(c);
            }

            count++;
        }
        return res[n - 1]; 
    }
};
