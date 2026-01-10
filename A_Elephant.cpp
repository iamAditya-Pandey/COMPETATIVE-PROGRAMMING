#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int fullSteps = x / 5;
    int remainder = x % 5;
    int result = fullSteps + (remainder > 0 ? 1 : 0);

    cout << result << "\n";
    return 0;
}
