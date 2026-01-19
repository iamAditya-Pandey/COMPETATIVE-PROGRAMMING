#include<bits/stdc++.h>
using namespace std ;

int main (){
    
    int t,n,s;
    cin >> t   ;
    cin >> n >> s ;
    int arr[n];
    for(int j = 1; j <= t ; t++){
    for(int i = 0; i < n-1;i++){
        cin>> arr[i];
    }
    sort(arr,arr + n);
    int left = abs(s - arr[0]);
    int right = abs(s - arr[n-1]);
    if(left < right ){
        cout << 2*left + right ;
    }
    else if (right < left){
        cout << 2*right + left ;
    }
    else{
        cout << 0;
    }
}
    return 0;
}