class Solution {
public:
    int calPoints(vector<string>& ops) {
        int len = ops.size();
        int res = 0;
        int pos = 0;
        int points[1001] = {0};
        for (int i = 0; i < len; i++) {
            switch(ops[i][0]) {
                case '+':
                if (pos < 0) continue;
                if (pos == 0) points[0] = 0;
                else if (pos == 1) 
                    points[pos] = points[pos - 1];
                else 
                    points[pos] = points[pos - 1] + points[pos - 2];
                res += points[pos];
                pos++;
                break;
                case 'D':
                if (pos == 0) points[0] = 0;
                else {
                    points[pos] = points[pos - 1] * 2;
                }
                res += points[pos];                
                pos++;
                break;
                case 'C':
                if (pos == 0) continue;
                pos--;
                res -= points[pos];
                break;
                default:
                points[pos++] = atoi(ops[i].c_str());
                res += points[pos - 1];
                break;
            }
        }
        return res;
    }
};
