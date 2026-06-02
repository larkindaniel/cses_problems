#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);   
    const long long MOD = 1'000'000'007;

    int n; 
    cin >> n; 
    vector<long long>dp(n+1,0);
    dp[0] = 1; 

    for (int i = 1; i <= n; ++i){
        for (int roll = 1; roll <= 6; ++roll){
            if (i >= roll) dp[i] +=  (dp[i-roll]);
            dp[i]%=MOD;
        }
    }
    cout << dp[n]%MOD << '\n';


}