class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = 1; i <= N; i++) {
            bitset<32> bits(i);
            string str = bits.to_string();
            str.erase(0, str.find_first_of("1", 0));
            if (S.find(str) == string::npos) return false;
        }
        return true;
    }
};
