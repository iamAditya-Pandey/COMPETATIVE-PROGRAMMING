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

       int n,q;
    cin>>n>>q;

    const long double pi=acosl(-1.0L);
    const long long SCALE=1e12;

    vector<long long> ag(n+1);

    rep1(i,n){
        int x,y;
        cin>>x>>y;
        long double ang=atan2((long double)y,(long double)x);
        if(ang<0) ang+=2*pi;
        ang=2*pi-ang;
        if(ang>=2*pi) ang-=2*pi;
        ag[i]=(long long)(ang*SCALE);
    }

    vector<long long> st;
    rep1(i,n) st.push_back(ag[i]);
    sort(all(st));

    while(q--){
        int A,B;
        cin>>A>>B;
        long long a=ag[A],b=ag[B];
        int ans=0;
        if(a<=b) ans=upper_bound(all(st),b)-lower_bound(all(st),a);
        else{
            ans+=st.end()-lower_bound(all(st),a);
            ans+=upper_bound(all(st),b)-st.begin();
        }
        cout<<ans<<endl;
    }
    return 0;

}
