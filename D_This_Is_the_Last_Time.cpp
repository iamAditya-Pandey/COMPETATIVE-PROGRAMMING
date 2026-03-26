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
    int n,k;
    cin>>n>>k;

    vvi cs(n,vi(3));
    rep(i,n) cin>>cs[i][0]>>cs[i][1]>>cs[i][2]; 
    

    sorta(cs); 

    int cur=k;
    int i=0;

    priority_queue<pair<int,int>> pq; //{reali,r}

    while(true){
        // +(valid) cs with l<=cur
        while(i<n && cs[i][0]<=cur){
            pq.push({cs[i][2],cs[i][1]});
            i++;
        }

        // -(invalid) cs (r<cur)
        while(!pq.empty() && pq.top().second<cur) pq.pop();
        if(pq.empty()) break;
        auto top=pq.top();
        pq.pop();
        if(top.first<=cur) break;
        cur=top.first;
    }
    cout<<cur<<endl;
    }

    return 0;
}