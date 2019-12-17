class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        int index[3][50000] = {0};
        int residx = 0;
        for (int i = 0; i < nums.size(); i++) {
            index[0][nums[i]]++;
            if (index[0][nums[i]] == 1) index[1][nums[i]] = i + 1;
            else index[2][nums[i]] = i + 1;
            if (index[0][residx] < index[0][nums[i]]) residx = nums[i];
            else if (index[0][residx] == index[0][nums[i]]) {
                if (index[0][residx] != 1 && index[2][nums[i]] - index[1][nums[i]] < index[2][residx] - index[1][residx]) residx = nums[i]; 
            }
        }
        if (index[2][residx] == 0) return 1;
        return index[2][residx] - index[1][residx] + 1;
    }
};
