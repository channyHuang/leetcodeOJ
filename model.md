string

```c++
//string split
vector<string> split(string path, string delimiters = " ") {
    vector<string> res;
    string::size_type prePos = path.find_first_not_of(delimiters, 0);
    string::size_type nextPos = path.find_first_of(delimiters, prePos);
    while (prePos != string::npos || nextPos != string::npos) {
        res.push_back(path.substr(prePos, nextPos - prePos));
        prePos = path.find_first_not_of(delimiters, nextPos);
        nextPos = path.find_first_of(delimiters, prePos);
    }
    return res;
}
```
