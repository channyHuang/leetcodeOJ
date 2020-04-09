class TweetCounts {
public:
    TweetCounts() {
        maps.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        itr = maps.find(tweetName);
        if (itr == maps.end()) {
            vector<int> vec;
            vec.push_back(time);
            maps.insert(pair<string, vector<int>>(tweetName, vec));
        } else {
            itr->second.push_back(time);
            int pos = itr->second.size() - 1;
            while (pos > 0 && itr->second[pos] < itr->second[pos - 1]) {
                int tmp = itr->second[pos];
                itr->second[pos] = itr->second[pos - 1];
                itr->second[pos - 1] = tmp;
                pos--;
            }
        }
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        itr = maps.find(tweetName);
        vector<int> res;
        if (itr == maps.end()) {
            return res;
        }
        int base = (freq == "minute" ? 60 : (freq == "hour" ? 3600 : 86400));
        int stPos = 0;
        for (int stTime = startTime; stTime <= endTime; ) {
            long long eTime = min(stTime + base, endTime + 1);
            int pst = find(stPos, itr->second.size() - 1, true, stTime, itr->second);
            if (pst == -1) {
                res.push_back(0);
                if (stTime + base > endTime) break;
                stTime = eTime;
                continue;
            }
            int ped = find(pst, itr->second.size() - 1, false, eTime, itr->second);
            if (ped == -1) res.push_back(0);
            else res.push_back(ped - pst + 1);
            if (eTime > endTime) break;
            stTime = eTime;
            if (ped != -1) stPos = ped;
        }
        return res;
    }

    int find(int stPos, int endPos, bool larger, int target, vector<int>& num) {
        int res = -1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (num[midPos] >= target) {
                endPos = midPos - 1;
                if (larger) {
                    res = midPos;
                }
            } else {
                stPos = midPos + 1;
                if (!larger) {
                    res = midPos;
                }
            }
        }
        return res;
    }

private:
    map<string, vector<int>> maps;
    map<string, vector<int>>::iterator itr;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
