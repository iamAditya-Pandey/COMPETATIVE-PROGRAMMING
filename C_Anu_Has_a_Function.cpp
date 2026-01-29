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

    vi a(n),b(n);
    rep(i,n){
        cin>>a[i];
        b[i]=~a[i];
    }

    if(n==1){
        cout<<a[0]<<endl;
        return 0;
    }

    vi l(n),r(n);
    l[0]=b[0];
    for(int i=1;i<n;i++){
        l[i]=l[i-1]&b[i];
    }

    r[n-1]=b[n-1];
    for(int i=n-2;i>=0;i--){
        r[i]=r[i+1]&b[i];
    }

    int ans=a[0]&r[1];
    int pos=0;

    if ((a[n-1] & l[n-2])>ans){
        ans=a[n-1]&l[n-2];
        pos=n-1;
    }

    for (int i=1;i<n-1;i++){
        int t=l[i-1] & a[i]&r[i+1];
        if(t>ans){
            ans=t;
            pos=i;
        }
    }

    swap(a[0],a[pos]);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}




