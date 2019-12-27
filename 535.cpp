class Solution {
public:
    map<int, string> maps;
    int count;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        maps.insert(make_pair(count, longUrl));
        count++;
        return "http://tinyurl.com/" + to_string(count - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int idx = stol(shortUrl.substr(19));
        map<int, string>::iterator itr = maps.find(idx);
        return itr->second;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
