#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    ll K;
    cin >> N >> K >> X;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end(), greater<ll>());

    // If all deliciousness are equal
    if (A[0] == A[N - 1]) {
        ll val = A[0] * K;
        for (int i = 0; i < X; i++) {
            cout << val << '\n';
        }
        return 0;
    }

    vector<ll> diff;
    for (int i = 1; i < N; i++) {
        diff.push_back(A[i] - A[0]); // negative or zero
    }

    ll base = A[0] * K;

    priority_queue<pair<ll, vector<int>>> pq;
    map<vector<int>, bool> used;

    vector<int> start(diff.size(), 0);
    pq.push({base, start});
    used[start] = true;

    for (int cnt = 0; cnt < X; cnt++) {
        auto cur = pq.top();
        pq.pop();

        ll val = cur.first;
        vector<int> v = cur.second;

        cout << val << '\n';

        for (int i = 0; i < (int)diff.size(); i++) {
            vector<int> nv = v;
            nv[i]++;
            ll used_cnt = 0;
            for (int x : nv) used_cnt += x;
            if (used_cnt > K) continue;
            if (used[nv]) continue;
            used[nv] = true;
            pq.push({val + diff[i], nv});
        }
    }

    return 0;
}
