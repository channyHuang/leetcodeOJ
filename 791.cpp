class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> maps;
        map<char, int>::iterator itr;
        for (int i = 0; i < S.length(); i++) {
            maps.insert(pair<char, int>(S[i], i));
        }
        int len = T.length();
        int endPos = len - 1;
        while (endPos >= 0) {
            if (maps.find(T[endPos]) == maps.end()) endPos--;
            else break;
        }
        if (endPos <= 0) return T;
        if (maps.find(T[0]) == maps.end()) {
            char tmp = T[0];
            T[0] = T[endPos];
            T[endPos] = tmp;
        }
        while (endPos >= 0) {
            if (maps.find(T[endPos]) == maps.end()) endPos--;
            else break;
        }
        for (int i = 1; i <= endPos; i++) {
            itr = maps.find(T[i]);
            if (itr == maps.end()) {
                char tmp = T[i];
                T[i] = T[endPos];
                T[endPos] = tmp;
                while (endPos >= 0) {
                    if (maps.find(T[endPos]) == maps.end()) endPos--;
                    else break;
                }
            }
            itr = maps.find(T[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (maps.find(T[j])->second > itr->second) {
                    char tmp = T[j];
                    T[j] = T[j + 1];
                    T[j + 1] = tmp;
                } else break;
            }
            
        }
        return T;
    }
};
