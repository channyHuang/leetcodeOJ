class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        string::size_type pos = input.find_first_of("+-*", 0);
        if (pos == string::npos) {
            int tmp = 0;
            int len = input.length();
            for (int i = 0; i < len; i++) {
                tmp = tmp * 10 + - '0' + input[i];
            }
            res.push_back(tmp);
            return res;
        }

        while (pos != string::npos) {   
            //map<int, int> maps;
            //map<int, int>::iterator itr;
            vector<int> preval = diffWaysToCompute(input.substr(0, pos));
            vector<int> nextval = diffWaysToCompute(input.substr(pos + 1));
            long long tmp = 0;
            for (int i = 0; i < preval.size(); i++) {
                for (int j = 0; j < nextval.size(); j++) {
                    switch(input[pos]) {
                    case '+':
                    tmp = preval[i] + nextval[j];
                    break;
                    case '-':
                    tmp = preval[i] - nextval[j];
                    break;
                    case '*':
                    tmp = preval[i] * nextval[j];
                    break;
                    default:
                    break;
                    }
                    //if (maps.find(tmp) != maps.end()) continue;
                    res.push_back(tmp);
                    //maps.insert(pair<int, int>(tmp, 1));
                }
            }

            pos = input.find_first_of("+-*", pos + 1);
        }
        return res;
    }
};
