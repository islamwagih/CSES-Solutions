#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6+1, INF = 1e9, M = 100;
int memo[N], coins[M], n, x;
int solve(int c){
    ///base cases
    if(c == 0){
        return 0;
    }
    int& res = memo[c];
    ///see if it was calculated before
    if(res !=  -1){
        return res;
    }

    ///if not then call it recursively
    res = INF;
    for(int i=0;i<n;i++){
        if(c >= coins[i]){
            res = min(res, 1+solve(c-coins[i]));
        }
    }
    return res;
}



int main(){
    fastInputOutput();
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    for(int i=0;i<N;i++){
        memo[i] = -1;
    }
    int ans = solve(x);
    cout<<(ans >= 1e9 ? -1 : ans)<<endl;
    return 0;
}
