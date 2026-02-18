#include <bits/stdc++.h>
using namespace std;

long long minCostLine(vector<long long>& a) {
    vector<long long> st;
    st.push_back(1e18); // sentinel

    long long cost = 0;

    for (long long x : a) {
        while (!st.empty() && st.back() <= x) {
            long long mid = st.back();
            st.pop_back();
            cost += min(st.back(), x);
        }
        st.push_back(x);
    }

    while (st.size() > 2) {
        long long mid = st.back(); 
        st.pop_back();
        cost += st.back();
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long mx = *max_element(a.begin(), a.end());
        
        // collect all rotations starting at a max
        vector<vector<long long>> starts;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx) {
                vector<long long> b;
                for (int j = 0; j < n; j++)
                    b.push_back(a[(i + j) % n]);
                cout << minCostLine(b) << "\n";
                break; // first max is enough
            }
        }
    }
}
