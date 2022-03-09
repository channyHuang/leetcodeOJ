class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        vector<int> res;
        blen = big.size();
        slen = small.size();
        unordered_map<int, int> indexmap;
        for (int i = 0; i < slen; ++i) {
            indexmap[small[i]] = i;
        }

        int stpos = 0, endpos = 0;
        while (stpos < blen && indexmap.find(big[stpos]) == indexmap.end()) stpos++;
        if (stpos >= blen) return res;

        vector<int> has(slen, 0);
        int count = 0;
        endpos = findTotal(big, stpos, indexmap, has, count);
        if (endpos >= blen) return res;
        // has result
        res.push_back(stpos);
        res.push_back(endpos);
        while (endpos < blen) {
            auto itr = indexmap.find(big[stpos]);
            has[itr->second]--;
            if (has[itr->second] == 0) count--;
            stpos++;
			while (stpos < blen && indexmap.find(big[stpos]) == indexmap.end()) stpos++;
			if (stpos >= blen) return res;

            while (count >= slen) {
                if (endpos - stpos < res[1] - res[0]) {
                    res[0] = stpos;
                    res[1] = endpos;
                }

				itr = indexmap.find(big[stpos]);
				has[itr->second]--;
				if (has[itr->second] == 0) count--;
                stpos++;
				while (stpos < blen && indexmap.find(big[stpos]) == indexmap.end()) stpos++;
				if (stpos >= blen) return res;
            }
            endpos = findTotal(big, endpos + 1, indexmap, has, count);
            if (endpos < blen) {
				if (endpos - stpos < res[1] - res[0]) {
					res[0] = stpos;
					res[1] = endpos;
				}
            }
        }

        return res;
    }

    int findTotal(vector<int>& big, int stpos, unordered_map<int, int>& indexmap, vector<int>& has, int &count) {
        int endpos = stpos;
        while (endpos < blen) {
			auto itr = indexmap.find(big[endpos]);
			if (itr == indexmap.end()) {
				endpos++;
				continue;
			}
			has[itr->second]++;
			if (has[itr->second] > 1) {
				endpos++;
				continue;
			}
			count++;
            if (count >= slen) return endpos;
            endpos++;
        }
        return endpos;
    }

private:
    int blen, slen;
};
