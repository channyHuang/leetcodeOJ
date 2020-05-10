class Solution {
public:
    class Node {
    public:
        int idx;
        string src;
        string dst;
        Node (int _idx = 0, string _src = "", string _dst = "") {
            idx = _idx;
            src = _src;
            dst = _dst;
        }
    };

    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int lens = S.length();
        int len = indexes.size();
        string res;
        int stpos = 0;
        vector<Node> vec(len, Node());
        for (int i = 0; i < len; i++) {         
            vec[i] = Node(indexes[i], sources[i], targets[i]);
        }
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < len; i++) {
            if (S.substr(vec[i].idx, vec[i].src.length()) != vec[i].src) continue;
            res += S.substr(stpos, vec[i].idx - stpos);
            res += vec[i].dst;
            stpos = vec[i].idx + vec[i].src.length();
        }
        res += S.substr(stpos, lens - stpos);
        return res;
    }

    static bool cmp(Node& a, Node& b) {
        return a.idx < b.idx;
    }
};
