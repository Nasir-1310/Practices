#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> firstPos;
    int maxLen = 0, start = 0;

    for (int i = 0; i < s.size(); i++) {
        if (firstPos.count(s[i])) {
            int len = i - firstPos[s[i]] - 1;
            if (len > maxLen) {
                maxLen = len;
                start = firstPos[s[i]] + 1;
            }
        } else {
            firstPos[s[i]] = i;
        }
    }

    if (maxLen > 0)
        cout << s.substr(start, maxLen);
    else
        cout << "No valid substring";

    return 0;
}
