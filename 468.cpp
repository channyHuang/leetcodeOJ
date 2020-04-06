class Solution {
public:
    string validIPAddress(string IP) {
        int len = IP.length();
        int cnt1 = count(IP.begin(), IP.end(), '.');
        int cnt2 = count(IP.begin(), IP.end(), ':');
        if (cnt1 != 3 && cnt2 != 7) return "Neither";
        if (IP.length() >= 40) return "Neither";
        vector<string> vec;

        if (cnt1 == 3) {
            string::size_type pos = IP.find_first_not_of(".");
            string::size_type nextPos = IP.find_first_of(".", pos);
            while (pos != string::npos || nextPos != string::npos) {
                vec.push_back(IP.substr(pos, nextPos - pos));
                pos = IP.find_first_not_of(".", nextPos);
                nextPos = IP.find_first_of(".", pos);
            }
            if (vec.size() != 4) return "Neither";
            for (int i = 0; i < 4; i++) {
                if (vec[i].length() > 1 && vec[i][0] == '0') return "Neither";
                int tmp = 0;
                for (int j = 0; j < vec[i].length(); j++) {
                    if (vec[i][j] > '9' || vec[i][j] < '0') return "Neither";
                    tmp = tmp * 10 + vec[i][j] - '0';
                    if (tmp > 255) return "Neither";
                }
                if (tmp < 0 || tmp > 255) return "Neither";
            }
            return "IPv4";
        } else {
            string::size_type pos = IP.find_first_not_of(":");
            string::size_type nextPos = IP.find_first_of(":", pos);
            while (pos != string::npos || nextPos != string::npos) {
                vec.push_back(IP.substr(pos, nextPos - pos));
                pos = IP.find_first_not_of(":", nextPos);
                nextPos = IP.find_first_of(":", pos);
            }
            if (vec.size() != 8) return "Neither";
            for (int i = 0; i < 8; i++) {
                if (vec[i].length() > 4) return "Neither";
                for (int j = 0; j < vec[i].length(); j++) {
                    if (vec[i][j] <= '9' && vec[i][j] >= '0') continue;
                    if (vec[i][j] >= 'a' && vec[i][j] <= 'f') continue;
                    if (vec[i][j] >= 'A' && vec[i][j] <= 'F') continue;
                    return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};
