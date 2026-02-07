#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> odds, evens;
        for (long long x : a) {
            if (x % 2) odds.push_back(x);
            else evens.push_back(x);
        }

        if (odds.size() >= 2) {
            cout << odds[odds.size()-2] << " " << odds.back() << "\n";
        } 
        else if (evens.size() >= 2) {
            cout << evens[evens.size()-2] << " " << evens.back() << "\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}
