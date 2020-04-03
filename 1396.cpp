class UndergroundSystem {
public:
    UndergroundSystem() {
        people.clear();
        times.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<string, int> curPair(stationName, t);
        people.insert(pair<int, pair<string, int>>(id, curPair));
    }
    
    void checkOut(int id, string stationName, int t) {
        map<int, pair<string, int>>::iterator itr = people.find(id);
        if (itr == people.end()) return;
        string stEnd = itr->second.first + "." + stationName;
        map<string, pair<double, int>>::iterator timeItr = times.find(stEnd);
        if (timeItr == times.end()) {
            times.insert(pair<string, pair<double, int>>(stEnd, pair<double, int>(t - itr->second.second, 1)));
        } else {
            timeItr->second.first += (t - itr->second.second);
            timeItr->second.second++;
        }
        people.erase(itr);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string stEnd = startStation + "." + endStation;
        map<string, pair<double, int>>::iterator timeItr = times.find(stEnd);
        return timeItr->second.first / timeItr->second.second;
    }

private:
    map<int, pair<string, int>> people;
    map<string, pair<double, int>> times;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
