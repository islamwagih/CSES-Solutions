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

const int N = (1e5)+5;
vector<int> graph[N];
int visited[N];
int color[N];
bool dfs(int node, int c){
    visited[node] = 1;
    color[node] = c;
    for(int child:graph[node]){
        if(!visited[child]){
           if(dfs(child, c^1) == 0){
                return 0;
           }
        }else{
            if(color[child] == color[node]) return 0;
        }
    }
    return 1;
}


int main(){

    fastInputOutput();
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a, b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int node=1;node<=n;node++){
        if(!visited[node]){
            if(dfs(node, 1) == 0){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }


    for(int node=1;node<=n;node++){
        cout<<(color[node] == 1 ? 1:2)<<' ';
    }


    return 0;

}
