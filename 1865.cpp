class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        for (int i = 0; i < len1; ++i) {
            maps1[nums1[i]]++;
        }
        for (int i = 0; i < len2; ++i) {
            maps2[nums2[i]]++;
            nums2_.push_back(nums2[i]);
        }
    }
    
    void add(int index, int val) {
        auto itr = maps2.find(nums2_[index]);
        if (itr == maps2.end()) return; // will not happen
        if (itr->second == 1) {
            maps2.erase(itr);
        } else {
            itr->second--;
        }
        nums2_[index] += val;
        maps2[nums2_[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (auto itr1 = maps1.begin(); itr1 != maps1.end(); itr1++) {
            if (tot < itr1->first) continue;
            int target = tot - itr1->first;
            auto itr = maps2.find(target);
            if (itr == maps2.end()) continue;
            res += (itr->second * itr1->second);
        }
        return res;
    }

private:
    unordered_map<int, int> maps1, maps2;
    vector<int> nums2_;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
