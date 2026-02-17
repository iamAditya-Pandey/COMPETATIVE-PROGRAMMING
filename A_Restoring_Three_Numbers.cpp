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
#define all(x) (x).begin(), (x).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Debug macro (optional, use only in local testing)
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = " << x << endl;
#else
    #define debug(x)
#endif

int32_t main() {
    fast_io;

            int a,b,c,d;
            cin>>a>>b>>c>>d;

            int e =0;

            e = max({a,b,c,d});

            if(e==a){
                cout<<(e-b)<<" "<<(e-c)<<" "<<(e-d);
            }
            else if(e==b){
                 cout<<(e-a)<<" "<<(e-c)<<" "<<(e-d);
            }
            else if(e==c){
                 cout<<(e-b)<<" "<<(e-a)<<" "<<(e-d);
            }
            else{
                 cout<<(e-b)<<" "<<(e-c)<<" "<<(e-a);
            }
}