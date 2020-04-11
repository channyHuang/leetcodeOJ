class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> maps;
        unordered_map<string, unordered_map<string, double>>::iterator itr;
        int len = equations.size();
        for (int i = 0; i < len; i++) {
            itr = maps.find(equations[i][0]);
            if (itr == maps.end()) {
                unordered_map<string, double> sub;
                sub.insert(pair<string, double>(equations[i][1], values[i]));
                maps.insert(pair<string, unordered_map<string, double>>(equations[i][0], sub));
            } else {
                itr->second.insert(pair<string, double>(equations[i][1], values[i]));
            }
            itr = maps.find(equations[i][1]);
            if (itr == maps.end()) {
                unordered_map<string, double> sub;
                sub.insert(pair<string, double>(equations[i][0], 1.0/values[i]));
                maps.insert(pair<string, unordered_map<string, double>>(equations[i][1], sub));
            } else {
                itr->second.insert(pair<string, double>(equations[i][0], 1.0/values[i]));
            }
        }
        len = queries.size();
        vector<double> res;
        for (int i = 0; i < len; i++) {
            itr = maps.find(queries[i][0]);
            if (itr == maps.end() || maps.find(queries[i][1]) == maps.end()) {
                res.push_back(-1.0);
                continue;
            }
            if (queries[i][0] == queries[i][1]) {
                res.push_back(1.0);
                continue;
            }
            double value = -1.0;
            unordered_map<string, double>::iterator tmpItr;
            stack<pair<string, double>> st;
            set<string> sets;
            sets.insert(queries[i][0]);
            for (tmpItr = itr->second.begin(); tmpItr != itr->second.end(); tmpItr++) {
                if (tmpItr->first == queries[i][1]) {
                    value = tmpItr->second;
                    break;
                }
                st.push(*tmpItr);
                sets.insert(tmpItr->first);
                value = dfs(maps, queries[i], st, sets);
                if (value != -1.0) break;
                st.pop();
            }
            res.push_back(value);
        }
        return res;
    }

    double dfs(unordered_map<string, unordered_map<string, double>> maps, vector<string>& querie, stack<pair<string, double>>& st, set<string>& sets) {
        unordered_map<string, unordered_map<string, double>>::iterator itr = maps.find(st.top().first);
        unordered_map<string, double>::iterator tmpItr;
        double value;
        for (tmpItr = itr->second.begin(); tmpItr != itr->second.end(); tmpItr++) {
            if (sets.find(tmpItr->first) != sets.end()) continue;
            if (tmpItr->first == querie[1]) return st.top().second * tmpItr->second;
            st.push(pair<string, double>(tmpItr->first, st.top().second * tmpItr->second));
            sets.insert(tmpItr->first);
            value = dfs(maps, querie, st, sets);
            if (value != -1.0) return value;
            sets.erase(tmpItr->first);
            st.pop();
        }
        return -1.0;
    }
};
