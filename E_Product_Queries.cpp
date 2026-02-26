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
    
    const int inf=1e18;

    int t;
    cin >> t;

    while (t--) {
        // Write your test case logic here
         int n;
        cin>>n;

        vi a(n);
        rep(i,n) cin>>a[i];

        vi cnt(n+1,0);
        for (int x:a) cnt[x]++;

        vi val;
        for (int i=2;i<=n;i++){
            if (cnt[i]) val.push_back(i);
        }

        vi ans(n+1,inf);

        if(cnt[1]) ans[1]=1;

        for (int x:val) ans[x]=1;

        rep1(i,n){
            if (ans[i]==inf) continue;
            for (int v:val){
                if(i*v>n) break;
                ans[i*v] = min(ans[i*v],ans[i]+1);
            }
        }

         rep1(i,n){
            if (ans[i]==inf) cout<<-1<<" ";
            else cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}