#include <bits/stdc++.h>
using namespace std;

int originalIdx(vector<pair<int, int>> a, int eleToCompare, bool rev = false){
    int maxSize = a.size();
    if(!rev){
        for(int i=0;i<maxSize;i++){
            if(a[i].first == eleToCompare){
                return a[i].second;
            }
        }
    }else{
        for(int i=maxSize-1;i>-1;i--){
            if(a[i].first == eleToCompare){
                return a[i].second;
            }
        }
    }
    return -1;
}

int main(){

    int n,target;cin>>n>>target;
    ///vector to save each element with its original idx
    vector<pair<int , int>> table;

    ///allocate n elements for the array
    int* arr = new int[n];

    ///input for the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
        table.push_back({arr[i], i});
    }
    sort(arr, arr+n);

    ///using two pointers
    int low = 0, high = n-1;
    while(low < high){
        int sum = arr[low] + arr[high];
        if(sum == target){
            int lowIdx = originalIdx(table, arr[low]);
            int highIdx = originalIdx(table, arr[high]);
            if(lowIdx < highIdx){
                cout<<lowIdx+1<<' '<<highIdx+1<<endl;
            }else if(lowIdx > highIdx){
                cout<<highIdx+1<<' '<<lowIdx+1<<endl;
            }else{
                ///traverse in reverse order to avoid same index for duplicates elements
                highIdx = originalIdx(table, arr[high], true);
                cout<<min(lowIdx, highIdx)+1<<' '<<max(lowIdx, highIdx)+1<<endl;
            }
            return 0;
        }else if(sum < target){
            low++;
        }else{
            high--;
        }
    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}
