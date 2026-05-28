#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200010;
long long prefix[N] = {}; 



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q; 
    cin >> n >> q; 
    for (int i = 1; i <= n; ++i){
        int a;
        cin >> a; 
        prefix[i] = prefix[i-1] + a;  
    }
    while (q--){
        int a,b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a-1] << '\n';
    }

}