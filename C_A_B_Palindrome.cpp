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
         int a,b;
        cin>>a>>b;

        string s;
        cin>>s;

        int n = s.size();
        int zero = 0, one = 0;
        bool ok = true;

        for (int i=0;i<n/2;i++){
            int j = n - 1 - i;

            if (s[i]!='?' && s[j]!='?' && s[i]!=s[j]) {
                ok = false;
                break;
            }

            if (s[i]=='?' && s[j]!='?') s[i] = s[j];
            if (s[j]=='?' && s[i]!='?') s[j] = s[i];
        }

        if (!ok) {
            cout <<"-1"<<endl;
            continue;
        }
        for (char c:s) {
            if (c=='0') zero++;
            if (c=='1') one++;
        }

        for (int i=0;i<n/2;i++){
            int j = n-1-i;

            if (s[i]=='?' && s[j]=='?') {
                if (zero+2<= a) {
                    s[i] = s[j] = '0';
                    zero += 2;
                } else if (one+2 <= b) {
                    s[i] = s[j] = '1';
                    one += 2;
                } else {
                    ok=false;
                    break;
                }
            }
        }
        if (n%2==1 && s[n/2]=='?') {
            if (zero+1<= a) {
                s[n/2] = '0';
                zero++;
            } else if (one + 1 <= b) {
                s[n/2] = '1';
                one++;
            } else {
                ok = false;
            }
        }
        if (zero!=a || one!=b) ok = false;

        cout<<(ok?s:"-1")<<endl;
    }

    return 0;
}