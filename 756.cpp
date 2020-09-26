class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {   
        maps.clear();    
        for (int i = 0; i < allowed.size(); i++) {
            map<string, vector<char>>::iterator itr = maps.find(allowed[i].substr(0, 2));
            if (itr == maps.end()) {
                maps.insert(make_pair(allowed[i].substr(0, 2), vector<char>(1, allowed[i][2])));
            } else {
                itr->second.push_back(allowed[i][2]);
            }
        } 
        flag = false;
        string nextBot = bottom.substr(0, bottom.length() - 1);
        search(bottom, nextBot, 0);
        return flag;
    }

    void search(string bottom, string nextBot, int pos) {
        //cout << bottom << " " << nextBot << " " << pos << endl;
        if (bottom.size() == 1 || flag) {
            flag = true;
            return;
        }
        if (pos == nextBot.length()) { 
            string tmp = nextBot.substr(0, nextBot.length() - 1);   
            search(nextBot, tmp, 0);
            return;
        }
        string key = bottom.substr(pos, 2);
        map<string, vector<char>>::iterator itr = maps.find(key);
        if (itr == maps.end()) {
            return;
        }
        for (int j = 0; j < itr->second.size(); j++) {
            nextBot[pos] = itr->second[j];
            search(bottom, nextBot, pos + 1);
        }
    }

private:
    bool flag;
    map<string, vector<char>> maps;
    //map<string, vector<char>>::iterator itr;
};
