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

const int N = 1e5+5;
const int inf = 2e9+1;

vector<pair<int, int>> vec;
int main(){
    fastInputOutput();
    int n, x;cin>>n>>x;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        vec.push_back({a, i});
    }
    sort(vec.begin(), vec.end());
    for(int i=0;i<n;i++){
        int l = 0, r = n-1;
        int target = x-vec[i].first;
        while(l < r){
            int sum = vec[l].first + vec[r].first;
            if(sum == target && l != i && r != i){
                cout<<vec[l].second<<' '<<vec[r].second<<' '<<vec[i].second<<endl;
                return 0;
            }
            if(sum < target){
                l++;
            }else{
                r--;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}
