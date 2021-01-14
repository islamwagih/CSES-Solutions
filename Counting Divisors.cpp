#include <bits/stdc++.h>
#define MAXSIZE (int)(1e6)+(1)
using namespace std;

int arr[MAXSIZE];

void sieve(int arr[], int n){
    arr[0] = 0;
    arr[1] = 0;
    for(int i=2;i<=n/i;i++){
        if(arr[i] == i){
            for(int j=i*i;j<n;j+=i){
                if(arr[j] > i)
                    arr[j] = i;
            }
        }
    }
}

vector<pair<int, int>> factorize(int n){
    vector<pair<int, int>> ret;
    while(n > 1){
        int curr = arr[n];
        int cnt = 0;
        while(n%curr == 0){
            cnt++;
            n/=curr;
        }
        ret.push_back({curr, cnt});
    }
    return ret;
}

int main(){
    int n;cin>>n;
    for(int i=0;i<MAXSIZE;i++){
        arr[i] = i;
    }
    sieve(arr, MAXSIZE);
    while(n--){
        int test;cin>>test;
        vector<pair<int, int>> factors = factorize(test);
        int divs = 1, factorsSize = factors.size();
        for(int i=0;i<factorsSize;i++){
            divs*=factors[i].second+1;
        }
        cout<<divs<<endl;
    }
    return 0;
}
