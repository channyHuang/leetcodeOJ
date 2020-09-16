class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int len = nums.size();
        count.push_back(1);
        newlen = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1]) count[newlen - 1]++;
            else {
                nums[newlen] = nums[i];
                count.push_back(1);
                newlen++;
            }
        }
        if (newlen <= 2) return false;      
        stvec.push_back(make_pair(0, count[0]));
        for (int i = 1; i < newlen; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                stvec.push_back(make_pair(i, count[i]));
                endvec.push_back(make_pair(i - 1, count[i - 1]));
                continue;
            }
            if (count[i] > count[i - 1]) {
                stvec.push_back(make_pair(i, count[i] - count[i - 1]));
            } else if (count[i] < count[i - 1]) {
                endvec.push_back(make_pair(i - 1, count[i - 1] - count[i]));
            }
        }
        endvec.push_back(make_pair(newlen - 1, count[newlen - 1]));
        int endPos = 0;

        /*cout << "-----" << endl;
        for (int i = 0; i < stvec.size(); i++) {
            cout << stvec[i].first << " " << stvec[i].second << endl;
        }
        for (int i = 0; i < endvec.size(); i++) {
            cout << endvec[i].first << " " << endvec[i].second << endl;
        }
        cout << "-----" << endl;*/

        for (int i = 0; i < stvec.size(); i++) {
            if (endPos >= endvec.size()) {
                //cout << "0" << endl;
                return false;
            }
            if (nums[endvec[endPos].first] - nums[stvec[i].first] < 2) {
                //cout << "1" << endl;
                return false;
            }
            if (nums[endvec[endPos].first] - nums[stvec[i].first] != endvec[endPos].first - stvec[i].first) return false;
            //cout << i << " " << endPos << " " << endvec[endPos].second << " " << stvec[i].second << endl;
            if (endvec[endPos].second < stvec[i].second) {
                stvec[i].second -= endvec[endPos].second;
                endPos++;
                i--;
            } else if (endvec[endPos].second == stvec[i].second) {
                stvec[i].second = 0;
                endPos++;
            } else {               
                endvec[endPos].second -= stvec[i].second;
                stvec[i].second = 0;
            }
        }
        //cout << "***** " << endPos << " " << stvec[stvec.size() - 1].second << endl;
        if (endPos != endvec.size()) return false;
        if (stvec[stvec.size() - 1].second != 0) return false;
        return true;
    }

private:
    vector<int> count;
    int newlen;
    vector<pair<int, int>> stvec;
    vector<pair<int, int>> endvec;
};
