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

    int n;
    cin>>n;
vector<string> s(n);
rep(i,n) cin>>s[i];

vvi cst(n,vi(n+1,0));

    rep(i,n){
        vi pre(n+1,0);
        vi suf(n+1,0);
    for(int j=0;j<n;j++) pre[j+1]=pre[j]+(s[i][j]=='#');
    for(int j=n-1;j>=0;j--)  suf[j]=suf[j+1]+(s[i][j]=='.');
for(int j=0;j<=n;j++) cst[i][j]=pre[j]+suf[j];
        }

const long long inf=1e18;
vector<long long> dp(n+2,inf);
vector<long long> ndp(n+2,inf);

for(int j=0;j<=n;j++) dp[j]=cst[0][j];

    for(int i=1;i<n;i++){
        long long mn=inf;
    for(int j=n;j>=0;j--){
        mn=min(mn,dp[j]);
        ndp[j]=mn+cst[i][j];
        }
    dp.swap(ndp);
    }
    cout<<*min_element(dp.begin(),dp.begin()+n+1)<<endl;
    return 0;
}