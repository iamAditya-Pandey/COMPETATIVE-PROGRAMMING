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
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vi a(n);
        rep(i,n) cin>>a[i];

        vector<pair<int,int>>v;
        rep(i, n) v.push_back({a[i],i});

        sorta(v);

        vector<int>pre(n);
        pre[0] = v[0].first;
        for (int i=1;i<n;i++)
            pre[i] = pre[i-1] + v[i].first;

        vi ans(n);

        for (int i = 0;i<n;i++){
            int j = i;
            int found = i;

            while (j<n){
                int target =pre[j];

                int l = j;
                int  r =n-1;
                int idx = j;

                while (l <=r){
                    int mid = (l+r)/2;
                    if (v[mid].first <=target){
                        idx = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }

                if (idx == j) break;

                found += idx-j;
                j = idx;
            }
            ans[v[i].second] = found;
        }

        rep(i,n){
            cout<<ans[i]<<" ";
        }

        cout<<endl;
    }
    return 0;
}