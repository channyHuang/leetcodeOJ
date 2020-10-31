class Solution {
public:
    struct Node {
    public:
        int fuel;
        int location;
        
        bool operator < (const Node& a) const {
            if (fuel == a.fuel) return location > a.location;
            return fuel > a.fuel;
        }

        Node(int _fuel = 0, int _loc = 0) : location(_loc), fuel(_fuel) {}
    };

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        len = stations.size();
        res = 0;
        int cur = 0; //current location
        int leftOil = startFuel; //left fuel in car
        int stPos = 0;
        set<Node> sets;

        while (stPos < len) {
            if (cur + leftOil >= target) return res;

            while (stPos < len) {
                if (stations[stPos][0] > cur + leftOil) break;
                sets.insert(Node(stations[stPos][1], stations[stPos][0]));
                stPos++;
            }

            if (sets.empty()) {
                return (cur + leftOil >= target ? res : -1);
            } else {
                res++;
                int addLocation = (*sets.begin()).location;
                leftOil -= (addLocation - cur);
                cur = addLocation;
                leftOil += (*sets.begin()).fuel;

                sets.erase(sets.begin());
                /*while (!sets.empty() && (*sets.begin()).location <= cur) {
                    sets.erase(sets.begin());
                } */
            }            
        }

        if (cur + leftOil >= target) return res;

        while (!sets.empty())
        {
            if (cur + leftOil >= target) return res;
            res++;
            int addLocation = (*sets.begin()).location;
            leftOil -= (addLocation - cur);
            cur = addLocation;
            leftOil += (*sets.begin()).fuel;

            sets.erase(sets.begin());
            /*
            while (!sets.empty() && (*sets.begin()).location <= cur) {
                sets.erase(sets.begin());
            }  */
        }

        return (cur + leftOil >= target ? res : -1);
    }

private:
    int len;
    int res;
};
