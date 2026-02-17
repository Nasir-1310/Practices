// Using no loops, print this pattern for a given number n:

// n, n-5, n-10,....0,....,n-10,n-5,n. Example: 7, 2, -3, 2, 7
#include <iostream>
using namespace std;

int n;

void print_pattern(int x, bool down) {
    cout << x << " ";

    // when we come back to n after going down, stop
    if (x == n && !down) return;

    if (down) {
        if (x - 5 <= 0)
            print_pattern(x - 5, false);
        else
            print_pattern(x - 5, true);
    } else {
        print_pattern(x + 5, false);
    }
}

int main() {
    cin >> n;
    print_pattern(n, true);
    return 0;
}
