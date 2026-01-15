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

   int x;
   cin>>x;


   int n ;
   cin>>n;
   vector<int>a(n);
   set<int>s;

   for(int i=0;i<n;i++){
    cin>>a[i];
    s.insert(a[i]);
   }

   int m;
   cin>>m;

   vector<int>b(m);
   for(int i=0;i<m;i++){
    cin>>b[i];
    s.insert(b[i]);
   }

   if(s.size()==x){
    cout<<"I become the guy."<<endl;
   }
   else{
    cout<<"Oh, my keyboard!"<<endl;
   }

   
}

