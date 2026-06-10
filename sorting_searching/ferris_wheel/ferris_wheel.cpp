#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 200005; 
int arr[MAX_N];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x; 
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    sort(arr,arr+n);

    int res = 0; 

    int r = n-1;
    int l = 0; 

    while (l < r){
        if (arr[l] + arr[r] <= x){
            l +=1; 
            r -=1; 
        } else{
            r -=1; 
        }
        res += 1; 
       
    }
    if (l == r) res +=1;
    cout << res << '\n';
}