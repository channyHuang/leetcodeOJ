class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int len = words.size();
		vector<int> freq;
		vector<int> res;
		for (int i = 0; i < len; i++) {
			freq.push_back(calcFreq(words[i]));
		}
		sort(freq.begin(), freq.end());
		int lenq = queries.size();
		for (int i = 0; i < lenq; i++) {
			int fq = calcFreq(queries[i]);
			int subres = 0;
			
			if (len == 1) {
				if (freq[0] > fq) subres = 1;
				res.push_back(subres);
				continue;
			}
			
			if (freq[0] > fq) subres = len;
			else if (freq[len - 1] <= fq) subres = 0;
			else {
				int stPos = 0;
				while (freq[stPos] <= fq) stPos++;
				subres = len - stPos;
			}
			res.push_back(subres);
		}
        return res;
    }
	
	int calcFreq(const string str) {
		int len = str.length();
		char c = 'z';
		int count = 0;
		for (int i = 0; i < len; i++) {
			if (c > str[i]) {
				c = str[i];
				count = 1;
			} else if (c == str[i]) count++;
		}
		return count;
	}
};
