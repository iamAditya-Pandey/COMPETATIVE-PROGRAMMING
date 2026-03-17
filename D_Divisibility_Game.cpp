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

static int lc(int a,int b,int cp){
    int g=__gcd(a,b);
    int v=(a/g)*b;
    if(v>cp) return cp+1;
    return v;
}

int32_t main() {
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        // Write your test case logic here
         int n,m;
        cin>>n>>m;
        int mx=n+m;

        vector<int>a(n),b(m);
        rep(i,n) cin>>a[i];
        rep(i,m) cin>>b[i];

        vector<char>in (mx+1,0);
        for(int x:a) in[x]=1;

        int L=1;
        for(int i=1;i<=mx;i++){
            if(in[i]){
                L=lc(L,i,mx);
                if(L>mx) break;
            }
        }

        vector<char> dv(mx+1,0);
        for(int i=1;i<=mx;i++){
            if(!in[i]) continue;
            for(int j=i;j<=mx;j+=i) dv[j]=1;
        }

        int c=0,d=0,s=0;
        for(int y:b){
            bool flg=(L<=mx && y%L==0);
            if(flg) c++;
            else if(!dv[y]) d++;
            else s++;
        }

        bool ok;
        if(s%2==0) ok=(c>d);
        else ok=(c>=d);

        if(ok)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }

    return 0;
}