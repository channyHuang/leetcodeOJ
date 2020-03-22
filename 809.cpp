class Solution {
public:
    class Node {
    public: 
        char c;
        int count;
        Node(char _c = ' ', int _count = 0) {
            c = _c;
            count = _count;
        }
    };

    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        int len = words.size();
        if (S.length() <= 0) {
            for (int i = 0; i < len; i++) {
                if (words[i].length() > 0) continue;
                res++;
            }
            return res;
        }
        Node nodes[105];
        nodes[0] = Node(S[0], 1);
        int pos = 0;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == S[i - 1]) nodes[pos].count++;
            else {
                pos++;
                nodes[pos] = Node(S[i], 1);
            }
        }
        
        for (int i = 0; i < len; i++) {
            int curPos = 0;
            int j = 1;
            char curChar = words[i][0];
            int curCount = 1;
            bool flag = true;
            while (words[i][j] != '\0') {
                if (words[i][j] == words[i][j - 1]) curCount++;
                else {
                    if (curChar != nodes[curPos].c || curCount > nodes[curPos].count) {
                        flag = false;
                        break;
                    }
                    if ((nodes[curPos].count > curCount) && (nodes[curPos].count - curCount < 2)) {
                        flag = false;
                        break;
                    }
                    curChar = words[i][j];
                    curCount = 1;
                    curPos++;
                    if (curPos > pos) {
                        flag = false;
                        break;
                    }
                }
                j++;
            }
            if (curChar != nodes[curPos].c || curCount > nodes[curPos].count) continue;
            if ((nodes[curPos].count > curCount) && (nodes[curPos].count - curCount < 2)) continue;
            if (curPos < pos) continue;
            if (flag) {
                res++;
            }
        }
        return res;
    }
};
