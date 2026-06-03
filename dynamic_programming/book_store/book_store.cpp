#include <bits/stdc++.h>
using namespace std;

int h[1010] = {}; 
int s[1010] = {};

int dp[100010] = {};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);   
    int n,budget;
    cin >> n >> budget; 
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> s[i];

    // let dp[i][j] => maximum number of books you can buy with budget i with s[0...j]
    /*
        dp[n]
    
    */

    for (int j = 0; j < n; ++j){
        for (int n = budget; n >= h[j]; --n){
            dp[n] = max(dp[n], s[j] + dp[n-h[j]]);
        }
    }
    cout << dp[budget] << '\n';
    
   

}