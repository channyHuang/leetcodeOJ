class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[256] = {0};
        int mlen = magazine.length();
        int rlen = ransomNote.length();
        for (int i = 0; i < mlen; i++) {
            count[(unsigned char)magazine[i]]++;
        }
        for (int i = 0; i < rlen; i++) {
            if (count[(unsigned char)ransomNote[i]] <= 0) return false;
            count[(unsigned char)ransomNote[i]]--;
        }
        return true;
    }
};
