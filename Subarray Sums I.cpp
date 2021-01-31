#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int main(){
    fastInputOutput();
    int n, x, total = 0;cin>>n>>x;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int left = 0, right = 0, sum = 0;
    bool noIncrement = 0;
    while(left < n){
        if(!noIncrement)
            sum += arr[right];
        if(sum < x){
            if(right == n){
                break;
            }
            right++;
            noIncrement = 0;
        }else if(sum > x){
            sum -= arr[left];
            left++;
            noIncrement = 1;
        }else{
            total++;
            sum -= arr[left];
            left++;
            noIncrement = 1;
        }
    }
    cout<<total<<endl;
    return 0;
}
