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
 int n,pos,l,r;
    cin>>n>>pos>>l>>r;

    int num=0;

    if(l>1 && r<n){
        if(pos<=l){
            num=(r-pos)+2;
        }
        else if(r<=pos){
            num=(pos-l)+2;
        }
        else if(pos-l<=r-pos){
            num=(pos-l) + (r-l)+2;
        }
        else {
            num=(r-pos)+(r-l)+2;
        }
    }
    else if(l==1 && r<n){
        if(pos<=r){
            num=(r-pos)+1;
        }
        else{
            num=(pos-r)+1;
        }
    }
    else if(l>1 && r==n){
        if(pos<l){
            num=(l-pos)+1;
        }
        else{
            num=(pos-l)+1;
        }
    }
    cout<<num<<endl;
    return 0;
}

