class Solution {
public:
    bool judgeCircle(string moves) {
        int len = moves.length();
        int x = 0, y = 0;
        for (int i = 0; i < len; i++) {
            switch(moves[i]) {
                case 'R':
                x++;
                break;
                case 'L':
                x--;
                break;
                case 'U':
                y++;
                break;
                case 'D':
                y--;
                break;
                default:
                break;
            }
        }
        if (x == 0 && y == 0) return true;
        else return false;
    }
};
