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


int a[200000];
int pre[30][200001];

int ran(int l,int r){
    int ans=0;
    rep(i,30){
        if(pre[i][r+1]-pre[i][l]==0){
            ans|=(1<<i);
        }
    }
    return ans;
}

int32_t main() {
    fast_io;

    int t;
    cin >> t;

    while (t--) {
        // Write your test case logic here
        int n;
        cin>>n;

        rep(i,n){
        cin>>a[i];
        }

        rep(j,30){
        pre[j][0]=0;
        rep(i,n){
            pre[j][i+1]= pre[j][i]+(((a[i]>>j)&1)==0);
        }
    }
 
    int q;
    cin>>q;

    while(q--){
        int l,k;
        cin>>l>>k;
        l--;

        if(a[l]<k){
            cout<<-1<<' ';
            continue;
        }

        int lo=l;
        int hi=n-1;
        while(lo<hi){
            int mid=(lo+hi+1)/2;
            if (ran(l,mid)>=k){
                lo=mid;
            } 
            else{
                hi=mid-1;
            }
        }

        cout<<lo+1<<' ';
    }
    cout<<endl;
    }

    return 0;
}
