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

int main(){
    fastInputOutput();
    int n;cin>>n;
    int* arr = new int[n];
    ll g1, g2, minDiff = LONG_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int mask=0;mask<(1<<n);mask++){
        g1 = 0, g2 = 0;
        for(int bit=0;bit<n;bit++){
            if((mask>>bit)&1){
                g1 += arr[bit];
            }else{
                g2 += arr[bit];
            }
        }
        minDiff = min(abs(g1-g2), minDiff);
    }
    cout<<minDiff<<endl;
    delete[] arr;
    return 0;
}

