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


        //1 based indexing ki hai prefix ke liye
        vi a(n+1);
        rep1(i,n) cin>>a[i];

    vi po(n+1,0);
    vi pe(n+1,0);
    map<int,int> mpp;
    mpp[0] = 1;

    bool ok = false;

    //prefix pe is sum at even or po is sum at odd hai
    rep1(i,n){
        po[i] = po[i-1];
        pe[i] = pe[i-1];

        if (i%2) po[i]+=a[i];
        else pe[i]+=a[i];

        //pe-po
        int dif = po[i] - pe[i];
        mpp[dif]++;

        // if any (pe-po)repeat 
        if(mpp[dif]>=2){
            ok = true;
            break;
        }
    }

    if(ok){
        yes;
    }
    else{
        no;
    }
    }

    return 0;
}