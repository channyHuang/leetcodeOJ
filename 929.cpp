class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int> res;
        int len = emails.size();
        for (int i = 0; i < len; i++) {
            string::size_type pos = emails[i].find('@');
            string pre = emails[i].substr(0, pos);
            string next = emails[i].substr(pos);
            pre.erase(remove(pre.begin(), pre.end(), '.'), pre.end());
            pos = pre.find('+');
            if (pos != string::npos) pre.erase(pos, pre.length() - pos);
            if (res.find(string(pre + next)) == res.end()) 
                res.insert(make_pair(string(pre + next), 1));
        }
        return res.size();
    }
};
