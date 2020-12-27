class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stulen = students.size();
        int sanlen = sandwiches.size();
        int res = 0;
        vector<bool> used(stulen, false);
        int pos = 0;
        for (int i = 0, j; i < sanlen; i++) {
            for (j = 0; j < stulen; j++) {
                if (used[(pos + j + stulen) % stulen] || students[(pos + j + stulen) % stulen] != sandwiches[i]) continue;
                used[(pos + j + stulen) % stulen] = true;
                res++;
                pos = (pos + j + 1 + stulen) % stulen;
                break;
            }
            if (j >= stulen) break;
        }
        return stulen - res;
    }
};
