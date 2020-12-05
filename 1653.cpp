class Solution {
public:
    int minimumDeletions(string s) {
        int len = s.length();
        if (len <= 1) return 0;
        
        vector<int> preb(len + 1, 0);
        vector<int> aftera(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            preb[i] = preb[i - 1] + (s[i - 1] == 'b' ? 1 : 0);
        }
        for (int i = len - 1; i >= 0; i--) {
            aftera[i] = aftera[i + 1] + (s[i] == 'a' ? 1 : 0);
        }
        int minn = len;
        for (int i = 0; i <= len; i++) {
            if (preb[i] + aftera[i] < minn) {
                minn = preb[i] + aftera[i];
            }
        }
        return minn;
    }
};
