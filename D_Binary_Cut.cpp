#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin>>s;
        int cnt = 0;
        for (int i=0;i+1<s.size();i++)
            if (s[i]=='1' && s[i+1]=='0')
                cnt++;
        cout<<cnt+1<<endl;
    }
}
