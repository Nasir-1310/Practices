#include <bits/stdc++.h>
using namespace std;

string addStrings(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string res = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << addStrings(a, b);
    return 0;
}