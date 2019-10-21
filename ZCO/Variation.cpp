#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    int i = 0, j = 1;
    long long count = 0;
    while(i<n && j<n){
        if(i==j){
            j++;
            continue;
        }
        if(a[j]-a[i]<k){
            j++;
        }
        else{
            count+=n-j;
            i++;
        }
    }
    cout<<count<<endl;
}