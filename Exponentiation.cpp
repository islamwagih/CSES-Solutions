#include <iostream>
using namespace std;
unsigned long long power(unsigned long long x, unsigned long long p, unsigned long long MOD){
    unsigned long long answer = 1;
    while(p){
        if(p&1){
            answer = (answer*x)%MOD;
        }
        x = (x*x)%MOD;
        p >>= 1;
    }
    return answer;
}

int main(){
    int n;cin>>n;
    while(n--){
        int a,b;cin>>a>>b;
        cout<<power(a, b, int((1e9)+7))<<endl;
    }
    return 0;
}
