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
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        long long bs= -1;
        long long bc = 1;

        for (int i=1;i<=n;i++) {
            long long d,t;
            cin >>d>>t;

            long long speed = d/t;  

            if (speed>bs){
                bs = speed;
                bc= i;
            }
        }

        cout<<bc<<endl;
    }

    return 0;
}