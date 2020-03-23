class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        set<string> setres;
        set<string>::iterator itr;
        if (n == 0) return res;
        if (n == 1) {
            res.push_back("()");
            return res;
        }
        else {
            vector<string> mid = generateParenthesis(n - 1);
            for (int i = 0; i < mid.size(); i++) {
                setres.insert("(" + mid[i] + ")");
            }
        }
        
        for (int i = 1; i < n; i++) {
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(n - i);
            for (int x = 0; x < left.size(); x++) {
                for (int y = 0; y < right.size(); y++) {
                    setres.insert(left[x] + right[y]);
                }
            }
        }
        for (itr = setres.begin(); itr != setres.end(); itr++) {
            string subres = *itr;
            res.push_back(subres);
        }
        return res;
    }
};
