#include <bits/stdc++.h>
using namespace std;

long long kadane(const vector<long long>& v) {
    long long best = LLONG_MIN, curr = 0;
    for (long long x : v) {
        curr = max(x, curr + x);
        best = max(best, curr);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        if (k % 2 == 0) {
            // k even → final array = original
            cout << kadane(a) << "\n";
        } else {
            // k odd → Alice gets +1 * b[i] globally
            vector<long long> newA(n);
            for (int i = 0; i < n; i++)
                newA[i] = a[i] + b[i];
            cout << kadane(newA) << "\n";
        }
    }
    return 0;
}
