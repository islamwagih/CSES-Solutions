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
vector<int> adj[N];
int in[N], ans[N], idx, n, m;
void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i] == 0){
            in[i]--;
            q.push(i);
        }
    }
    while(q.size()){
        int curr = q.front();
        q.pop();
        ans[idx++] = curr;
        for(int child:adj[curr]){
            in[child]--;
            if(in[child] == 0){
                in[child]--;
                q.push(child);
            }
        }
    }

}
int main(){

    fastInputOutput();
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
        in[v]++;
    }
    bfs();
    if(idx < n){
        cout<<"IMPOSSIBLE\n";
    }else{
        for(int i=0;i<idx;i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }

    return 0;

}
