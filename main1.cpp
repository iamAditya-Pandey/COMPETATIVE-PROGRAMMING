#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) parent[b] = a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<string> names(n);
    for (auto &x : names) cin >> x;

    vector<int> skill(n);
    for (auto &x : skill) cin >> x;

    unordered_map<string, int> id;
    for (int i = 0; i < n; ++i) id[names[i]] = i;

    DSU dsu(n);

    int f; 
    cin >> f;
    while (f--) {
        string a, b;
        cin >> a >> b;
        dsu.unite(id[a], id[b]);
    }

    // group by root
    unordered_map<int, vector<int>> comp;
    for (int i = 0; i < n; ++i) comp[dsu.find(i)].push_back(i);

    vector<vector<int>> groups;
    vector<int> gSkill, gSize;
    for (auto &p : comp) {
        int sum = 0;
        for (int x : p.second) sum += skill[x];
        gSkill.push_back(sum);
        gSize.push_back((int)p.second.size());
        groups.push_back(p.second);
    }

    int g = groups.size();

    int r;
    cin >> r;
    vector<vector<int>> rival(g);
    for (int i = 0; i < r; ++i) {
        string a, b;
        cin >> a >> b;
        int ga = -1, gb = -1;
        for (int j = 0; j < g; ++j) {
            for (int x : groups[j]) {
                if (x == id[a]) ga = j;
                if (x == id[b]) gb = j;
            }
        }
        if (ga != -1 && gb != -1 && ga != gb) {
            rival[ga].push_back(gb);
            rival[gb].push_back(ga);
        }
    }

    int limit;
    cin >> limit;

    vector<int> conflict(g, 0);
    for (int i = 0; i < g; ++i)
        for (int j : rival[i])
            conflict[i] |= (1 << j);

    int total = 1 << g;
    vector<int> sumSkill(total), sumSize(total);

    for (int mask = 1; mask < total; ++mask) {
        int bit = __builtin_ctz(mask);
        int prev = mask ^ (1 << bit);
        sumSkill[mask] = sumSkill[prev] + gSkill[bit];
        sumSize[mask] = sumSize[prev] + gSize[bit];
    }

    int best = 0;
    for (int mask = 0; mask < total; ++mask) {
        if (sumSkill[mask] > limit) continue;
        bool ok = true;
        for (int i = 0; i < g; ++i)
            if ((mask >> i) & 1)
                if (conflict[i] & mask)
                    { ok = false; break; }
        if (ok) best = max(best, sumSize[mask]);
    }

    cout << best;
    return 0;
}
