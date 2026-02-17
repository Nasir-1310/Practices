#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string ans = "";
    for (int i = 0; i < n; i++) {
        // flip the diagonal bit
        ans += (a[i][i] == '0') ? '1' : '0';
    }

    cout << ans << endl;
    return 0;
}
