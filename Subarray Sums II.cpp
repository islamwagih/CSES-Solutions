#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}



const int N = (2e5)+5;
ll sum[N];
map<ll, ll> mp;

int main(){

    fastInputOutput();
    ll n, x;cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>sum[i];
        if(i > 0) sum[i] += sum[i-1];
        mp[sum[i]]++;
    }

    ll ans = mp[x];
    for(int i=0;i<n;i++){
        mp[sum[i]]--;
        ll right = x+sum[i];
        ans+=mp[right];
    }

    cout<<ans<<endl;

    return 0;

}
