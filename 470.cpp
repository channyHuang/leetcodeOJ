// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int num[7][7] = {1,2,3,4,5,6,7,
                     8,9,10,1,2,3,4,
                     5,6,7,8,9,10,1,
                     2,3,4,5,6,7,8,
                     9,10,1,2,3,4,5,
                     6,7,8,9,10,0,0,
                     0,0,0,0,0,0,0};

    int rand10() {
        int r = rand7();
        int c = rand7();

        while (num[r - 1][c - 1] == 0) {
            r = rand7();
            c = rand7();
        }

        return num[r - 1][c - 1];
    }
};
