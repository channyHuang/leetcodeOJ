class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<int, vector<int>> maps;
        map<int, vector<int>>::iterator itr;
        for (int i = 0; i < allowed.size(); i++) {
            int key = (allowed[i][0] - 'A') * 26 + (allowed[i][1] - 'A');
            int val = allowed[i][2] - 'A';
            itr = maps.find(key);
            if (itr == maps.end()) {
                vector<int> sub;
                sub.push_back(val);
                maps.insert(pair<int, vector<int>>(key, sub));
            } else itr->second.push_back(val);
        } 
        flag = false;
        vector<int> numBot;
        for (int i = 0; i < bottom.length(); i++) {
            numBot.push_back(bottom[i] - 'A');
        }
        vector<int> nextBot;
        nextBot.resize(numBot.size() - 1);
        search(numBot, maps, nextBot, 0);
        return flag;
    }

    void search(vector<int>& bottom, map<int, vector<int>> maps, vector<int>& nextBot, int pos) {
        if (bottom.size() == 1) {
            flag = true;
            return;
        }
        if (pos == bottom.size() - 1) {
            vector<int> tmp;
            tmp.resize(nextBot.size() - 1);        
            search(nextBot, maps, tmp, 0);
            return;
        }
        bool hasNext = true;
        for (int i = 1; i < bottom.size(); i++) {
            int key = bottom[i - 1] * 26 + bottom[i];
             map<int, vector<int>>::iterator itr = maps.find(key);
             if (itr == maps.end()) {
                 hasNext = false;
                 break;
             }
        }
        if (!hasNext) return;
        
        int key = bottom[pos] * 26 + bottom[pos + 1];
        map<int, vector<int>>::iterator itr = maps.find(key);
        if (itr == maps.end()) return;
        for (int j = 0; j < itr->second.size(); j++) {
            nextBot[pos] = itr->second[j];
            search(bottom, maps, nextBot, pos + 1);
        }
    }

private:
    bool flag;
};
