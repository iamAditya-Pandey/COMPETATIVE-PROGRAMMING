#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int b[101];
        for (int i = 1; i <= n; i++) {
            scanf("%d", b+i);
        }
        int pos[101] = {0};
        int m = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i]) { m++; pos[m] = i; }
        }
        
        bool ok = true;
        if (m == 0) ok = false;
        for (int i = 1; i <= m-1; i++) {
            if (pos[i+1] - pos[i] <= k) ok = false;
        }
        
        for (int i = 1; i <= n; i++) {
            bool found = false;
            for (int j = 1; j <= m; j++) {
                if (abs(i-pos[j]) <= k) {
                    found = true; break;
                }
            }
            if (!found) ok = false;
        }
        
        printf("%s\n", (ok? "Yes" : "No"));
    }
}