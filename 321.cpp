class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int min1 = (k <= len2 ? 0 : k - len2);
        int max1 = min(len1, k);
        vector<int> res;
        //init res
        for (int i = 0; i < len1; i++) {
            if (i >= k) break;
            res.push_back(nums1[i]);
        }
        if (len1 < k) {
            for (int i = 0; i < len2; i++) {
                res.push_back(nums2[i]);
                if (res.size() >= k) break;
            }
        }
        //for each case
        for (int i = min1; i <= max1; i++) {
            vector<int> sub1 = subMaxNumber(nums1, i);
            vector<int> sub2 = subMaxNumber(nums2, k - i);

            vector<int> sub(k, 0);
            int pos = 0;
            int larger = 0;
            vector<int>::iterator itr1 = sub1.begin();
            vector<int>::iterator itr2 = sub2.begin();
            while (itr1 != sub1.end() || itr2 != sub2.end()) {
                sub[pos++] = (lexicographical_compare(itr1, sub1.end(), itr2, sub2.end()) ? *itr2++ : *itr1++);
                if (larger == 0 && sub[pos - 1] > res[pos - 1]) larger = 1;
                else if (larger == 0 && sub[pos - 1] < res[pos - 1]) larger = -1;
            }

            if (larger > 0) {
                res = sub;
            }
        }
        return res;
    }

    vector<int> subMaxNumber(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == k) return nums;
        stack<int> st;
        st.push(nums[0]);
        int count = 0;
        int delk = len - k;
        for (int i = 1; i < len; i++) {
            if (!st.empty() && st.top() < nums[i] && count < delk) {
                st.pop();
                count++;
                i--;
            } else {
                st.push(nums[i]);
            }     
        }
        while (st.size() > k) {
            st.pop();
        }
        vector<int> res(k, 0);
        while (!st.empty()) {
            res[--k] = st.top();
            st.pop();
        }
        return res;
    }
};
