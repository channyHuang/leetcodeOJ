class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return false;
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(nums[i]);
            if (itr != maps.end()) {
                itr->second++;
            } else {
                maps.insert(pair<int, int>(nums[i], 1));
            }
        }
        if (maps.size() < 3) return false;
        int count = 0;
        int sum = 0;
        map<int, int>::iterator nextItr;
        int lastNum;
        int lastSum;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second == 0) continue;
            if (count == 0) {
                count = 1;
                sum = itr->second;
                lastSum = itr->second;
                lastNum = itr->first;
                nextItr = itr;
                nextItr++;
                itr->second -= sum;
                continue;
            }
            if (itr->first != lastNum + 1 || itr->second < lastSum) {
                if (count < 3) return false;
                itr = nextItr;
                count = 0;
                continue;
            }
            lastSum = itr->second;
            lastNum = itr->first;
            itr->second -= sum;
            
            count++;
        }   
        if (count != 0 && count < 3) return false;    
        return true;
    }
};
