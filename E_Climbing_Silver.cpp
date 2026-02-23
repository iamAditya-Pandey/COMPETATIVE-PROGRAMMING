// JAI SHREE RAM //
/*******************************************************
 * Author: Aditya Pandey
 * Purpose: Competitive Programming Template
 * Fast I/O + Optimized compilation flags
 *******************************************************/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define int long long  // Use 64-bit integers by default

// Common macros
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Sorting macros
#define sorta(x) sort(all(x))
#define sortd(x) sort((x).rbegin(), (x).rend())

// Loops
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (n); i >= 1; i--)

// Vector shortcuts (int type)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define vvpi vector<vector<pair<int,int>>>

// Debug macro
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
#else
    #define debug(x)
#endif

int32_t main() {
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        // Write your test case logic here
          int N, C;
    cin >> N >> C;
    C--; // Convert 1-based column to 0-based

    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    // Precompute the index of the nearest wall below each cell
    // below[i][j] stores the row index of the first '#' in column j with row index > i
    vector<vector<int>> below(N, vector<int>(N, -1));
    for (int j = 0; j < N; j++) {
        int last_wall_idx = -1;
        // Traverse from bottom to top to record the nearest wall below
        for (int i = N - 1; i >= 0; i--) {
            below[i][j] = last_wall_idx;
            if (S[i][j] == '#') {
                last_wall_idx = i;
            }
        }
    }

    // dp[i][j] stores whether cell (i, j) is reachable
    vector<vector<bool>> dp(N, vector<bool>(N, false));

    // Base case: Start position
    dp[N - 1][C] = true;

    // Process rows from bottom to top
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            // 1. Check if we are ALLOWED to enter cell (i, j)
            bool can_enter = false;
            if (S[i][j] == '.') {
                can_enter = true;
            } else {
                // It is a wall. We can enter only if the column below is clear.
                // This implies the nearest wall below must have been reachable (and thus destroyed).
                int b_idx = below[i][j];
                if (b_idx == -1) {
                    can_enter = true; // No walls below, safe to enter
                } else {
                    can_enter = dp[b_idx][j]; // Can enter only if the wall below was reachable
                }
            }

            if (!can_enter) {
                dp[i][j] = false;
                continue;
            }

            // 2. Check if we can REACH (i, j) from the previous row
            bool reachable_from_below = false;
            // Check (i+1, j-1), (i+1, j), (i+1, j+1)
            for (int d = -1; d <= 1; d++) {
                int nj = j + d;
                if (nj >= 0 && nj < N) {
                    if (dp[i + 1][nj]) {
                        reachable_from_below = true;
                        break;
                    }
                }
            }
            dp[i][j] = reachable_from_below;
        }
    }
    string ans = "";
    for (int j = 0; j < N; j++) {
        ans += (dp[0][j] ? '1' : '0');
    }
    cout << ans << "\n";
    }

    return 0;
}