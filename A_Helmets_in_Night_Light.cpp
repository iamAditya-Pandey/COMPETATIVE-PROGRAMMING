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

        int n,p;
        cin>>n>>p;
        

        vector<int>a(n);
        vector<int>b(n);
        vector<pair<int,int>>v(n);
        int ans =p;
        int done =1;
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

         for(int i=0;i<n;i++){
            cin>>b[i];
        }

        for(int i=0;i<n;i++){
            v[i]= {b[i], a[i]};
        }

         sort(v.begin(),v.end());

         for (auto it :v){

            if(done>=n)break;

            if(it.first>=p  ){
                ans += (n-done)*p;
                break;
            }

            if(it.second  >=(n-done)){

                ans += (n-done)*it.first;
                done =n;
                break;
                
            }

            else {
                ans += it.second * it.first;
                done += it.second;
            } 
         }
         cout<<ans<<endl;
    }
    return 0;
}


// // // JAI SHREE RAM //
// // /*******************************************************
// //  * Author: Aditya Pandey
// //  * Purpose: Competitive Programming Template
// //  *******************************************************/

// #include <bits/stdc++.h>
// using namespace std;

// #define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
// #define endl '\n'
// #define int long long  

// int32_t main() {
//     fast_io;

//     int t;
//     cin >> t;

//     while (t--) {

//         int n, p;
//         cin >> n >> p;

//         vector<int> a(n), b(n);
//         for (int &x : a) cin >> x;
//         for (int &x : b) cin >> x;

//         // pair -> (cost, capacity)
//         vector<pair<int,int>> v(n);

//         for (int i = 0; i < n; i++)
//             v[i] = {b[i], a[i]};

//         sort(v.begin(), v.end()); // sorted by cost

//         int done = 1; 
//         int ans = p;  // cost of first one

//         for (auto it : v) {

//             int cost = it.first;
//             int can = it.second;

//             if (done >= n) break;

//             if (cost >= p) {
//                 ans += (n - done) * p;
//                 break;
//             }

//             int need = n - done;

//             if (can >= need) {
//                 ans += need * cost;
//                 done = n;
//                 break;
//             } 
//             else {
//                 ans += can * cost;
//                 done += can;
//             }
//         }

//         cout << ans << endl;
//     }
//     return 0;
// }
