#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 200005; 
int arr[MAX_N];

long long solve(int n){

    long long prefix = 0;
    long long cand = 1LL; 
    for (int i = 0; i < n; ++i){
        prefix += arr[i];
        if (cand < arr[i]){
            return cand; 
        } 
        cand = prefix + 1; 
    }
    return cand;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n; 
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr,arr+n);
    cout << solve(n) << '\n';

}