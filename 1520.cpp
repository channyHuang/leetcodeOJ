class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int len = s.length();
        input = s;
        unordered_map<char, pair<int, int>> maps;
        unordered_map<char, pair<int, int>>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(s[i]);
            if (itr == maps.end()) {
                maps[s[i]] = make_pair(i, i);
            } else {
                itr->second.second = i;
            }
        }
        /*
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            cout << itr->first << " " << itr->second.first << " " << itr->second.second << endl;
        }*/

        for (itr = maps.begin(); itr != maps.end(); itr++) {
            int stPos = itr->second.first;
            int endPos = itr->second.second;
            int pos = stPos + 1;
            while (pos <= endPos) {
                if (maps[s[pos]].first < stPos) break;
                if (maps[s[pos]].second > endPos) endPos = maps[s[pos]].second;
                pos++;
            }
            if (pos <= endPos) continue;
            vec.push_back(make_pair(stPos, endPos));
        }
        //cout << vec.size() << endl;
        if (vec.size() <= 0) return res;
        sort(vec.begin(), vec.end(), cmp);
        /*
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].first << " " << vec[i].second << endl;
        }*/

        minLength = vec[0].second - vec[0].first + 1;
        res.push_back(s.substr(vec[0].first, vec[0].second - vec[0].first + 1));
        vector<int> index;
        search(0, 0, -1, index, 0);
        return res;
    }

    void search(int stIdx, int cnt, int lastEnd, vector<int>& index, int len) {
        if (cnt + vec.size() - stIdx < res.size()) return;
        if (stIdx >= vec.size()) {
            if (cnt > res.size() || (cnt == res.size() && len < minLength)) {
                res.clear();
                for (int i = 0; i < cnt; i++) {
                    res.push_back(input.substr(vec[index[i]].first, vec[index[i]].second - vec[index[i]].first + 1));
                }
                minLength = len;
            }
            return;
        }
        bool isEnd = true;
        for (int i = stIdx; i < vec.size(); i++) {
            if (vec[i].first <= lastEnd) continue;
            isEnd = false;
            index.push_back(i);
            search(i + 1, cnt + 1, vec[i].second, index, len + vec[i].second - vec[i].first + 1);
            index.pop_back();
        }

        if (isEnd) {
            if (cnt > res.size() || (cnt == res.size() && len < minLength)) {
                res.clear();
                for (int i = 0; i < cnt; i++) {
                    res.push_back(input.substr(vec[index[i]].first, vec[index[i]].second - vec[index[i]].first + 1));
                }
                minLength = len;
            }
            return;
        }
    }

    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }

private:
    vector<pair<int, int>> vec;
    vector<string> res;
    int minLength;
    string input;
};
