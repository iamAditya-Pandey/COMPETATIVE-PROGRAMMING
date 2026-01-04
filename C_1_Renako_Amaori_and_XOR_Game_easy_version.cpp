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
        int n;
        cin>>n;

        int aj=0;
        int ma =0;
        vector<int>a(n+1);
        vector<int>b(n+1);

       for(int i=1;i<=n;i++){
        cin>>a[i];
       }
       for(int i=1;i<=n;i++){
        cin>>b[i];
       }
      
        for (int i=1;i<=n;i++) {
            if (a[i]!=b[i]) {
                if ((i)%2==1){
                    aj++;
                }
                else{
                    ma--;
                };            
            }
        }
        if (aj>ma){
            cout<<"Ajisai"<<endl;
        }
       else if(ma>aj){
        cout<<"Mai"<<endl;
       }
       else{
        cout<<"Tie"<<endl;
       }

    }
    return 0;
}


