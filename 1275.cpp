class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
		string res;
		int len = moves.size();
		char maps[3][3]= {0};
        bool flag = false;
		for (int i = 0; i < len; i++) {
			maps[moves[i][0]][moves[i][1]] = (i % 2 ? 'B' : 'A');
		}
		for (int i = 0; i < 3; i++) {
			if (maps[i][1] != 0 && maps[i][0] == maps[i][1] && maps[i][2] == maps[i][1]) {
				res = maps[i][1];
				flag = true;
				break;
			} else if (maps[1][i] != 0 && maps[0][i] == maps[1][i] && maps[2][i] == maps[1][i]) {
				res = maps[1][i];
				flag = true;
				break;
			}
		}
		if (flag) return res;
		if (maps[1][1] != 0) {
			if (maps[0][0] == maps[1][1] && maps[2][2] == maps[1][1]) {
				res = maps[1][1];
				flag = true;
			} else if (maps[0][2] == maps[1][1] && maps[2][0] == maps[1][1]) {
				res = maps[1][1];
				flag = true;
			}
			if (flag) return res;
		}			
		if (len < 9) res = "Pending";
		else res = "Draw";
		return res;
    }
};
