class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int len = hand.size();
        if (W == 0 || len < W || len % W) return false;
        if (W == 1) return true;
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(hand[i]);
            if (itr == maps.end()) {
                maps.insert(pair<int, int>(hand[i], 1));
            } else {
                itr->second++;
            }
        }
        
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            int index = itr->first;
            int count = itr->second;
            
            if (count == 0) continue;
            int needMinuse = W;
            for (map<int, int>::iterator subitr = itr; subitr != maps.end(); subitr++) {
                if (subitr->first != index || subitr->second < count) return false;
                subitr->second -= count;
                needMinuse--;
                index++;
                if (needMinuse == 0) break;
            }
            if (needMinuse != 0) return false;
        }

        return true;
    }
};
