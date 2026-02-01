#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a < b) {
            cout << -1 << "\n";
            continue;
        }

        if (a == b) {
            cout << 0 << "\n\n";
            continue;
        }

        long long x = a ^ b; // single operation

        // x ≤ a always holds when a ≥ b
        cout << 1 << "\n";
        cout << x << "\n";
    }

    return 0;
}
