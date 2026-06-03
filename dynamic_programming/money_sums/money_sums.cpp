#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1 << 30; 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);  
    int n; 
    cin >> n; 
    int MAX_SUM = n*1000 + 5;

    vector<int>coins(n,0);
    vector<int>dp(MAX_SUM, -INF);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    dp[0] = 0;


    for (int i = 0; i < n; ++i){
        for (int sum = MAX_SUM-1; sum >= coins[i]; --sum){
            if (dp[sum-coins[i]] != -INF) dp[sum] = 1; 
        }
    }
    vector<int>res;
    for (int sum = 1; sum < MAX_SUM; ++sum){
        if (dp[sum] == 1) res.push_back(sum);
    }
    cout << res.size() << '\n';
    for (auto sum: res) cout <<  sum << " ";             
}