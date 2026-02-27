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
    int n,l,r;
    cin>>n>>l>>r;
    vi a(n);
    rep(i,n) cin>>a[i];

    vi s;
    rep(i,l) s.push_back(a[i]);
    for(int i=r;i<n;i++) s.push_back(a[i]);

    int mn=a[l];
    int id=l;
    for(int i=l+1;i<r;i++)
        if(a[i]<mn){
            mn=a[i];
            id=i;
        }

    vector<int>b;
    for(int i=id;i<r;i++) b.push_back(a[i]);
    for(int i=l;i<id;i++) b.push_back(a[i]);

    int w=s.size();
    for(int i=0;i<s.size();i++)
        if(s[i]>b[0]){
            w=i;
            break;
        }

    vector<int>ans;
    rep(i,w) ans.push_back(s[i]);
    for(int x:b) ans.push_back(x);
    for(int i=w;i<s.size();i++) ans.push_back(s[i]);

    rep(i,n)
        if(i+1==n) cout<<ans[i]<<endl;
        else  cout<<ans[i]<<' ';
    }
    return 0;
}
