/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < employees.size(); i++) {
            maps.insert(make_pair(employees[i]->id, i));
        }
        queue<int> qu;
        qu.push(id);
        int res = 0;
        while (!qu.empty()) {
            int curId = qu.front();
            qu.pop();
            itr = maps.find(curId);
            if (itr == maps.end()) continue;
            int idx = itr->second;
            res += employees[idx]->importance;
            for (int i = 0; i < employees[idx]->subordinates.size(); i++) {
                qu.push(employees[idx]->subordinates[i]);
            }
        }
        return res;
    }
};
