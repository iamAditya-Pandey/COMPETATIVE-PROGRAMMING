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

    int t;
    cin >> t;

    while (t--) {
        // Write your test case logic here
    string s;
    cin>>s;

    int n = s.size();

    int c1=0;
    int c2=0;

    for(int i=0;i<3;i++){
        c1 += (int)s[i];
    }
    for(int i=3;i<n;i++){
        c2 += (int)s[i];
    }

    if(c1 ==c2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }

    return 0;
}