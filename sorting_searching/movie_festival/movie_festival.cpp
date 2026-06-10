#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n; 
    vector<pair<int,int>>arr(n);
    for (int i = 0; i < n; ++i){
        int a,b; 
        cin >> a >> b; 
        arr[i] = {a,b};
    }
    sort(arr.begin(), arr.end(), [](const auto & a, const auto & b){
        return tie(a.second, b.first) < tie(b.second, a.first);
    });

    int res = 1; 
    int j = 0; 
    for (int i = 1; i < n; ++i){
        if (arr[j].second <= arr[i].first){
            j = i ; 
            res +=1;
        }
    }
    cout << res << '\n';
}