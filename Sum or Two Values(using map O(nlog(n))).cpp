#include <bits/stdc++.h>
using namespace std;
int main(){
    ///Note if you used unordered_map you will get TLE
   ///but we can avoid it using reserve method with value 1e7 	
    int n,x;cin>>n>>x;
    int* arr = new int[n];
    map<int, int> eleToIdx;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int curr = arr[i];
        int target = abs(curr-x);
        auto it = eleToIdx.find(target);
        if(it != eleToIdx.end()){
            bool must = (arr[it->second] + arr[i] == x);
            if(!must) continue;
            if(i < it->second){
                cout<<i+1<<' '<<it->second+1<<endl;
            }else{
                cout<<it->second+1<<' '<<i+1<<endl;
            }
            return 0;
        }else{
            eleToIdx.insert({arr[i], i});
        }
    }
    cout<<"IMPOSSIBLE\n";
 
    return 0;
}
