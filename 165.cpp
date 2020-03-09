class Solution {
public:
    int compareVersion(string version1, string version2) {      
        int pos1 = 0, pos2 = 0;
        while (1) {
            if (pos1 >= version1.length() && pos2 >= version2.length()) {
                return 0;
            }
            int v1 = 0, v2 = 0;
            while (pos1 < version1.length() && (version1[pos1] != '.') ) {
                v1 = v1 * 10 - '0' + version1[pos1];
                pos1++;
            }
            pos1++;
            while (pos2 < version2.length() && version2[pos2] != '.' ) {
                v2 = v2 * 10 - '0' + version2[pos2];
                pos2++;
            }
            pos2++;
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
        }
        return 0;
    }
};
