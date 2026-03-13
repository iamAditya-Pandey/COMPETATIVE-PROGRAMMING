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
        vi a(n);
        rep(i,n) cin>>a[i];
        vi o(6);
       rep(i,6){
            if(a[0]==i+1) o[i]=0;
            else o[i]=1;
}

        for(int i=1;i<n;i++){
            vi p(6,1e9);
            rep(j,6){
                int val;
            if(a[i]==j+1) val=0;
            else val=1;
                rep(k,6){
                    if(j!=k && j+k!=5){
                        p[j]=min(p[j],o[k]+val);
                    }
                }
            }
            o=p;
        }
        int ans=1e9;
        rep(i,6){
        ans=min(ans,o[i]);
        }
       cout<<ans<<endl;
    }
    return 0;
}

