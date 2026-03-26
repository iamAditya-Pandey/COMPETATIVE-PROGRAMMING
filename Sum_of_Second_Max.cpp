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
        int n;
        cin>>n;

        vi v(n),pos(n+1);
        rep(i,n){
            cin>>v[i];
            pos[v[i]]=i;
        }

        set<int> st;
        st.insert(-1);
        st.insert(n);

        int ans=0;

        for(int x=n;x>=1;x--){
            int i=pos[x];

            auto it=st.lower_bound(i);

            int r1=*it;
            int l1 = *prev(it);

            int r2=n,l2=-1;

            if(it != st.end()){
                auto it2 = next(it);
                if(it2 != st.end()) r2 = *it2;
            }

            if(it != st.begin()){
                auto it2 = prev(it);
                if(it2 != st.begin()){
                    it2=prev(it2);
                    l2=*it2;
                }
            }
            ans += x*((i-l1)*(r2-r1) + (l1-l2)*(r1-i));
            st.insert(i);
        }
        cout<<ans<<endl;
    }

    return 0;
}