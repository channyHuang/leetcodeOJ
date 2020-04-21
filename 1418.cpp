class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, map<string, int>> menus;
        map<string, map<string, int>>::iterator itr;
        int len = orders.size();
        vector<vector<string>> res;
        set<string> foodnames;
        set<int> tablenums;
        for (int i = 0; i < len; i++) {
            int num = 0;
            for (int j = 0; j < orders[i][1].length(); j++) {
                num = num * 10 + orders[i][1][j] - '0';
            }
            tablenums.insert(num);
            foodnames.insert(orders[i][2]);
            itr = menus.find(orders[i][2]);
            if (itr == menus.end()) {
                map<string, int> sub;
                sub.insert(pair<string, int>(orders[i][1], 1));
                menus.insert(pair<string, map<string, int>>(orders[i][2], sub));
            } else {
                map<string, int>::iterator subitr = itr->second.find(orders[i][1]);
                if (subitr == itr->second.end()) {
                    itr->second.insert(pair<string, int>(orders[i][1], 1));
                } else {
                    subitr->second++;
                }
            }
        }

        vector<string> resfirst;
        resfirst.push_back("Table");
        for (set<string>::iterator setitr = foodnames.begin(); setitr != foodnames.end(); setitr++) {
            resfirst.push_back(*setitr);
        }
        res.push_back(resfirst);
        for (set<int>::iterator setitr = tablenums.begin(); setitr != tablenums.end(); setitr++) {
            vector<string> line;
            line.push_back(to_string(*setitr));
            for (int i = 1; i < resfirst.size(); i++) {
                itr = menus.find(resfirst[i]);
                map<string, int>::iterator subitr = itr->second.find(to_string(*setitr));
                if (subitr == itr->second.end()) {
                    line.push_back("0");
                } else line.push_back(to_string(subitr->second));
            }
            res.push_back(line);
        }
        return res;
    }
};
