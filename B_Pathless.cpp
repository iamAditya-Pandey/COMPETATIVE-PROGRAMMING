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
    int n;
    cin>>n;
    int eq;
    cin>>eq;
    vi a(n);  
    map<int,int> mpp;
    rep(i,n){
        cin>>a[i];
        mpp[a[i]]++;
    }
    
    int sm=0;
    rep(i,n) sm=sm+a[i];

    if(eq<sm){
        for(auto i:a) cout<<i<<" ";
        cout<<endl;
        continue;
    }

    int rq=eq-sm;

    if(rq%2==0) cout<<-1<<endl;
        
    else{
        if(rq==1){
            rep(i,mpp[1]) cout<<1<<" ";
            rep(i,mpp[2]) cout<<2<<" ";
            rep(i,mpp[0]) cout<<0<<" ";
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    }

    return 0;
}