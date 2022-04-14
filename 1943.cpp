// sort的cmp需要保证cmp(a,b)和cmp(b,a)结果一致，否则在某些编译平台上(如leetcode)会运行出错

class Solution {
public:
    
    struct Node {
        long long pos;
        long long index;
        bool start;

        Node(long long _pos = 0, long long _index = 0, bool _start = false) : pos(_pos), index(_index), start(_start) {}
    };

    static bool cmp(Node &a, Node &b) {
        if (a.pos == b.pos) {
            if (a.start && !b.start) return true;
            else if (b.start) return false;
            return a.index < b.index;
        }
        return a.pos < b.pos;
    }

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        long long  slen = segments.size(); // slen >= 1
        vector<vector<long long>> res;
        vector<Node> nodes;
        for (long long  i = 0; i < slen; ++i) {
            nodes.push_back(Node(segments[i][0], i, true));
            nodes.push_back(Node(segments[i][1], i, false));
        }
        // nodes.size() >= 2
        long long nlen = nodes.size();
        sort(nodes.begin(), nodes.end(), cmp);
        long long stpos = nodes[0].pos, endpos = nodes[1].pos;
        unordered_map<long long, long long> maps;
        unordered_map<long long, long long>::iterator itr;
        maps[segments[nodes[0].index][2]]++;
        long long cursum = segments[nodes[0].index][2];
        long long pos = 1;
        long long curcolor;

        while (pos < nlen && nodes[pos].pos == stpos) {
            curcolor = segments[nodes[pos].index][2];
            itr = maps.find(curcolor);
            if (itr == maps.end()) {
                cursum += curcolor;
            }
            maps[curcolor]++;
            pos++;
        }
        endpos = stpos;
        while (pos < nlen) {
            endpos = nodes[pos].pos;
            long long nextsum = cursum;
            bool change = false;
            while (pos < nlen && nodes[pos].pos == endpos) {
                curcolor = segments[nodes[pos].index][2];
                itr = maps.find(curcolor);
                if (nodes[pos].start) {
                    if (itr == maps.end()) {
                        change = true;
                        nextsum += curcolor;
                    }
                    maps[curcolor]++;
                } else {
                    if (itr->second == 1) {
                        maps.erase(curcolor);
                        change = true;
                        nextsum -= curcolor;
                    } else {
                        maps[curcolor]--;
                    }
                }
                pos++;
            }
            if (change) {
                if (cursum > 0) {
                    vector<long long> sub = {stpos, endpos, cursum};
                    res.push_back(sub);
                }
                cursum = nextsum;
                stpos = endpos;
            }
        }
        return res;
    }
};
