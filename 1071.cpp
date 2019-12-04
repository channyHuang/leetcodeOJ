class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string res = "";
		int len1 = str1.length();
		int len2 = str2.length();
		if (len1 <= 0 || len2 <= 0) return res;
		
		if (len1 >= len2) {
			int j = 0;
			for (int i = 0; i < len1; i++) {
				if (str1[i] != str2[j]) return res;
				j++;
				if (j >= len2) j = 0;
			}
			int len = len1 % len2;
			if (len == 0) return str2;
			res = str1.substr(len1 - len, len);
			return gcdOfStrings(str2, res);
		} else {
			int j = 0;
			for (int i = 0; i < len2; i++) {
				if (str1[j] != str2[i]) return res;
				j++;
				if (j >= len1) j = 0;
			}
			int len = len2 % len1;
			if (len == 0) return str1;
			res = str2.substr(len2 - len, len);
			return gcdOfStrings(str1, res);
		}
		return res;
    }
};
