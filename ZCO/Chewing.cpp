#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    int n, k, num;
    cin>>n>>k;
    vector<int> a;
    for(int i = 0;i<n;i++){
        cin>>num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    long long count = 0;
    for(int i =0 ;i<n;i++){
        int index = lower_bound(a.begin(), a.end(), k-a[i]) - a.begin();
        if(index==0) continue;
        if(index-1>=i) count+=max(0, index-1-i);
    }
    cout<<count<<endl;
}