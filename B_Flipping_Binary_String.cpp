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
#define ll long long
#define nl cout << '\n'

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
        int n;
        cin>>n;

        string s;
        cin>>s;

        vi ans1,ans2;

        rep(i,n){
            if(s[i]=='1') ans1.pb(i+1);
            else ans2.pb(i+1);
        }

        if(ans1.size()==0){
            cout<<0<<endl;
        } 
        else if(ans1.size()%2==0 && ans2.size()%2==1){
            if(ans1.size()<ans2.size()){
                cout<<ans1.size()<<endl;
                for(auto i:ans1) cout<<i<<" ";
                cout<<endl;
            }
            else{
                cout<<ans2.size()<<endl;
                for(auto i:ans2) cout<<i<<" ";
                cout<<endl;
            }
        } 
        else if(ans1.size()%2==0){
            cout<<ans1.size()<<endl;
            for(auto i:ans1) cout<<i<<" ";
            cout<<endl;
        } 
        else if(ans2.size()%2==1){
            cout<<ans2.size()<<endl;
            for(auto i:ans2) cout<<i<<" ";
            cout<<endl;
        } 
        else cout<<-1<<endl;
        
    }

    return 0;
}