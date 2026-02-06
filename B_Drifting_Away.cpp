// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     if (!(cin >> t)) return 0;
//     while (t--) {
//         string s;
//         cin >> s;
//         int n = (int)s.size();
        
//         // Check for possible infinite loop (2-cycle)
//         bool infinite = false;
//         for (int i = 0; i + 1 < n; ++i) {
//             if ((s[i] == '>' || s[i] == '*') && (s[i+1] == '<' || s[i+1] == '*')) {
//                 infinite = true;
//                 break;
//             }
//         }
//         if (infinite) {
//             cout << -1 << '\n';
//             continue;
//         }
        
//         // Count consecutive '<' from start
//         int L = 0;
//         for (int i = 0; i < n && s[i] == '<'; ++i) ++L;
//         // Count consecutive '>' from end
//         int R = 0;
//         for (int i = n-1; i >= 0 && s[i] == '>'; --i) ++R;
//         // Is there any '*' ?
//         bool hasStar = (s.find('*') != string::npos);
        
//         int ans = max(L, R) + (hasStar ? 1 : 0);
//         cout << ans << '\n';
//     }
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         string s;
//         cin >> s;
//         int n = s.size();

//         // Check 2-cycle
//         for (int i = 0; i + 1 < n; ++i) {
//             if ((s[i] == '>' || s[i] == '*') && (s[i+1] == '<' || s[i+1] == '*')) {
//                 cout << -1 << '\n';
//                 goto next_test;
//             }
//         }

//         {
//             // count consecutive '<' from start
//             int L = 0;
//             while (L < n && s[L] == '<') L++;

//             // count consecutive '>' from end
//             int R = 0;
//             while (R < n && s[n - 1 - R] == '>') R++;

//             // if neither prefix nor suffix covers the whole string, answer = max(L, R) + 1
//             // otherwise, no '*' needed in the check
//             int ans = max(L, R) + ( (L + R < n) ? 1 : 0 );
//             cout << ans << '\n';
//         }
//         next_test:;
//     }
// }



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
        string s;
        cin>>s;

        int l=0;
            int r=0;

        int n= s.size();
        bool infinite = false;

        for(int i=0;i<n-1;i++){

            if((s[i]=='>' || s[i]=='*') &&  ( s[i+1]=='*'  || s[i+1]=='<')){
                infinite = true;
                continue;
            }
        }

        if(infinite){
            cout<<-1<<endl;
        }

        else{
           

            for(int i =0;i<n;i++){
                if(s[i]=='<')l++;
                else if(s[i]=='>')r++;
            }
        

        if((l+r)<n){
            cout<<max(l,r)+1<<endl;
        }
        else{
            cout<<max(l,r)<<endl;
        }
    }
}

    return 0;
}