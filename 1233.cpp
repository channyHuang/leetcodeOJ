class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        int len = folder.size();
        sort(folder.begin(), folder.end());
        res.push_back(folder[0]);
        int cnt = 0;
        for (int i = 1; i < len; i++) {
            if (folder[i].length() <= res[cnt].length()) {
                res.push_back(folder[i]);
                cnt++;
                continue;
            }
            if (folder[i].substr(0, res[cnt].length()) == res[cnt] && folder[i][res[cnt].length()] == '/') continue;
            res.push_back(folder[i]);
            cnt++;
        }
        return res;
    }
};
