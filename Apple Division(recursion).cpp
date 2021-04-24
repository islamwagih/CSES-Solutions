#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int n, apples[25];
ll solve(int ind, ll g1, ll g2){
   if(ind == n){
        return abs(g2-g1);
   }
   return min(solve(ind+1, g1+apples[ind], g2-apples[ind]), solve(ind+1, g1, g2));
}

int main(){
    fastInputOutput();
    cin>>n;
    ll g2 = 0;
    for(int i=0;i<n;i++){
        cin>>apples[i];
        g2 += apples[i];
    }
    cout<<solve(0, 0, g2)<<endl;
    return 0;
}

